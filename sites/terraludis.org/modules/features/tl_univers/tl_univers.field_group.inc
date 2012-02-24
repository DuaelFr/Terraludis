<?php
/**
 * @file
 * tl_univers.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tl_univers_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_og_options|node|groupe|form';
  $field_group->group_name = 'group_og_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'groupe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Paramètres du groupe',
    'weight' => '3',
    'children' => array(
      0 => 'field_group_type',
      1 => 'group_access',
      2 => 'og_roles_permissions',
      3 => 'group_group',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_og_options|node|groupe|form'] = $field_group;

  return $export;
}
