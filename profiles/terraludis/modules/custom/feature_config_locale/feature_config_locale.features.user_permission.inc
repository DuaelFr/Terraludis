<?php
/**
 * @file
 * feature_config_locale.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_config_locale_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(),
    'module' => 'locale',
  );

  return $permissions;
}
