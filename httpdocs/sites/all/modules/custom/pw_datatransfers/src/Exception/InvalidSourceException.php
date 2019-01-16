<?php
/**
 * Created by PhpStorm.
 * User: Tobias Krause
 * Date: 20.12.2018
 * Time: 15:21
 */

namespace Drupal\pw_datatransfers\Exception;


/**
 * Exception for cases where needed data could not be received from the
 * given source (CSV/ JSON)
 */
class InvalidSourceException extends DatatransfersException {

}