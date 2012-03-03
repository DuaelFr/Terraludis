<?php
/**
 * Filter handler for group audience:gid
 * 
 * In views interface : show multiselect with group names
 * In exposed filter : show checkboxes with group icons
 */
class og_handler_filter_group_audience_gid_tl extends views_handler_filter_many_to_one {
  
  function get_value_options() {

    // @TODO add extra settings to allow filtering by OG_STATE in og_get_all_group()
    $groups = og_load_multiple(og_get_all_group());
    
    foreach($groups as $group) {
      if ($group->access()) {
        $entity = reset(entity_load('node', array($group->etid)));
        if ($this->value_form_type == 'checkboxes') {
          $flang = field_language('node', $entity, 'field_icon');
          $imageData = array(
            'style_name' => 'universe_icon',
            'path' => !empty($entity->field_icon) ? $entity->field_icon[$flang][0]['filename'] : _tl_hacks_get_default_icon_uri(),
            'alt' => check_plain($entity->title),
            'title' => check_plain($entity->title),
          );
          $this->value_options[$group->gid] = theme('image_style', $imageData);
        } else {
          $this->value_options[$group->gid] = $entity->title;
        }
      }
    }
  }
  
  function value_form(&$form, &$form_state) {
    if (empty($form_state['form_id']) || $form_state['form_id'] != 'views_ui_config_item_form') {
      $this->value_form_type = 'checkboxes';
    }
    
    parent::value_form($form, $form_state);
    
    if (empty($form_state['form_id']) || $form_state['form_id'] != 'views_ui_config_item_form') {
	  $form['value']['#theme'] = 'select_as_checkboxes';
	}
  }
}