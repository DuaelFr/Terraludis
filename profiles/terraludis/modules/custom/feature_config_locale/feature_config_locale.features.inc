<?php
/**
 * @file
 * feature_config_locale.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_config_locale_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
