<?php

namespace Drupal\pw_datatransfers\Exception;

/**
 * Exception when an import check fails - for example because some of the data
 * which had to be imported were not found after import finished
 */
class ImportCheckFailed extends DatatransfersException {

}