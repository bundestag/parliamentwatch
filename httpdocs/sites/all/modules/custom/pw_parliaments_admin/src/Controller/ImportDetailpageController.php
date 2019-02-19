<?php


namespace Drupal\pw_parliaments_admin\Controller;

use Drupal\pw_parliaments_admin\Import\Import;
use Drupal\pw_parliaments_admin\Status\ImportStatus;

/**
 * Controller class for the import detail page. The page show different
 * views, forms and texts depending on the ImportType and the status of
 * the import
 */
class ImportDetailpageController {

  protected $import;


  protected $importStatus;


  /**
   * @var \Drupal\pw_parliaments_admin\Import\Interfaces\ImportTypeInterface|null
   */
  protected $importType;

  /**
   * Defines which is the next step in the import process.
   *
   * @var string|bool
   * Can be 'structure_data' or 'final_import', FALSE if no next step
   * is possible (due to errors for example)
   */
  protected $nextStep = FALSE;


  /**
   * ImportDetailpageController constructor.
   *
   * @param \Drupal\pw_parliaments_admin\Import\Import $import
   */
  public function __construct(Import $import) {
    $this->import = $import;
    $this->importStatus = $this->import->getStatus();
    $this->importType = $this->import->getImportTypeClass();
    $this->setNextStep();
  }


  /**
   * Get the text markup suitable for the status and import type
   *
   */
  public function getTextMarkup() {
    $output = '';
    switch ($this->importStatus) {
      case ImportStatus::OK:
        $output = '<div style="color: green; font-weight: bold;"><p>Die Validierung der Datensätze ergab keine Probleme. Du kannst die Datensätze hier noch einmal prüfen und mit dem Import der Datensätze fortfahren.</p></div>
<p>Im nächsten Schritt werden die Wahlkreise in die Datenstruktur umgeformt, wie sie für das Portal benötigt wird. Hier besteht noch einmal die Möglichkeit zu prüfen, ob die in einem letzten Schritt dann erstellten Wahlkreise den erwarteten Wahlkreisen entsprechen werden. </p>';
        break;
      case ImportStatus::FAILED:
        $output = '<div style="color: red; font-weight: bold;"><p>Die Validierung der Datensätze entdeckte einige Fehler. Bitte prüfe die Datensätze und erstelle einen neuen Import. Dazu kannst Du diese Datensätze mit den Fehlermeldungen exportieren und weiter bearbeiten.</p>
<p>Dieser fehlgeschlagene Import wird in spätestens einem Monat gelöscht.</p></div>';
        break;
      case ImportStatus::DATA_STRUCTURED_FAILED:
        $output = '<div style="color: red; font-weight: bold;"><p>Bei der Strukturierung der Datensätze sind Fehler aufgetreten. Bitte prüfe die Datensätze und erstelle einen neuen Import. Dazu kannst Du diese Datensätze mit den Fehlermeldungen exportieren und weiter bearbeiten.</p>
<p>Dieser Import wird in spätestens einem Monat gelöscht.</p></div>';
        break;
      case ImportStatus::DATA_STRUCTURED_OK:
        $output = '<div style="color: green; font-weight: bold;"><p>Die Strukturierung der Datensätze scheint ohne Probleme funktioniert zu haben. Du kannst die Daten, so wie sie im nächsten Schritt erstellt werden dürften, hier noch einmal prüfen und mit dem Import der Datensätze fortfahren.</p></div>
<p>Im nächsten Schritt werden die Wahlkreise importiert. </p>';
        break;
      case ImportStatus::IMPORT_FAILED:
        $output = '<div style="color: red; font-weight: bold;"><p>Beim Import der Daten scheint etwas schief gelaufen zu sein.</p></div>
<p>Prüfe die Fehlermeldungen und versuche es dann noch einmal. Elemente, die bereits importiert wurden, wenn nicht erneut importiert.</p>';
        break;
      case ImportStatus::IMPORTED:
        $output = '<div style="color: green; font-weight: bold;"><p>Der Import der Daten ist abgeschlossen.</p></div>';
        break;
    }

    return $output;
  }


  /**
   * Get the Drupal form array for the next step in import process
   *
   * @return array
   * Form array as build by drupal_get_form()
   */
  public function getForm() {
    switch ($this->nextStep) {
      case 'structure_data':
        module_load_include('inc', 'pw_parliaments_admin', 'forms/start_structuring_form');
        return drupal_get_form('pw_parliaments_admin_start_constituency_structuring', $this->import);
      case 'final_import':
        module_load_include('inc', 'pw_parliaments_admin', 'forms/final_import_form');
        return drupal_get_form('pw_parliaments_admin_start_constituency_final_import', $this->import);
    }
  }


  /**
   * Get the next step during import process
   *
   * @return bool|string
   */
  public function nextStep() {
    return $this->nextStep;
  }

  /**
   * Set which is the next step in import process
   */
  protected function setNextStep() {
    switch ($this->importStatus) {
      case ImportStatus::OK:
        if ($this->importType->needsDataStructuring()) {
          $this->nextStep = 'structure_data';
        }
        else {
          $this->nextStep = 'final_import';
        }
        break;
      case ImportStatus::DATA_STRUCTURED_OK:
        $this->nextStep = 'final_import';
        break;
      case ImportStatus::IMPORT_FAILED:
        $this->nextStep = 'final_import';
        break;
    }
  }


  /**
   * Get the render array for the view
   *
   * @return string
   */
  public function getView() {
    $view_name = '';
    $output = '';
    switch ($this->importStatus) {
      case ImportStatus::OK:
        $view_name = $this->importType->getViewName();
        break;
      case ImportStatus::FAILED:
        $view_name = $this->importType->getViewName();
        break;
      case ImportStatus::DATA_STRUCTURED_OK:
        $view_name = $this->importType->getViewName('structured_data');
        break;
      case ImportStatus::DATA_STRUCTURED_FAILED:
        $view_name = $this->importType->getViewName('structured_data');
        break;
      case ImportStatus::IMPORT_FAILED:
        if ($this->importType->needsDataStructuring()) {
          $view_name = $this->importType->getViewName('structured_data');
        }
        else {
          $view_name = $this->importType->getViewName();
        }
        break;
      case ImportStatus::IMPORTED:
        if ($this->importType->needsDataStructuring()) {
          $view_name = $this->importType->getViewName('structured_data');
        }
        else {
          $view_name = $this->importType->getViewName();
        }
        break;
    }

    $views = views_get_view($view_name);
    if ( is_object($views) ) {
      $views->set_display('default');
      $views->set_arguments([$this->import->getId()]);
      $views->pre_execute();
      $output = $views->render('default');
    }

    return $output;
  }
}