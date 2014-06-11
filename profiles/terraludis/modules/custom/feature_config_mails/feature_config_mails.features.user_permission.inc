<?php
/**
 * @file
 * feature_config_mails.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_config_mails_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(),
    'module' => 'mailsystem',
  );

  // Exported permission: 'choose htmlmail_plaintext'.
  $permissions['choose htmlmail_plaintext'] = array(
    'name' => 'choose htmlmail_plaintext',
    'roles' => array(),
    'module' => 'htmlmail',
  );

  // Exported permission: 'use text format mail'.
  $permissions['use text format mail'] = array(
    'name' => 'use text format mail',
    'roles' => array(),
    'module' => 'filter',
  );

  return $permissions;
}
