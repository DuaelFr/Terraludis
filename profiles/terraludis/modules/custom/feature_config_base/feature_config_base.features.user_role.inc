<?php
/**
 * @file
 * feature_config_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_config_base_user_default_roles() {
  $roles = array();

  // Exported role: Administrateur.
  $roles['Administrateur'] = array(
    'name' => 'Administrateur',
    'weight' => 2,
    'machine_name' => 'administrateur',
  );

  return $roles;
}
