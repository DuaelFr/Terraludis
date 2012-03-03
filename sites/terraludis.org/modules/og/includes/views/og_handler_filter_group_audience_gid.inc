<?php
/**
 * Filter handler for group audience:gid
 */
class og_handler_filter_group_audience_gid extends views_handler_filter_many_to_one {

  function get_value_options() {

    // @TODO add extra settings to allow filtering by OG_STATE in og_get_all_group()
    $groups = og_load_multiple(og_get_all_group());
    
    foreach($groups as $group) {
      if ($group->access()) {
        $this->value_options[$group->gid] = $group->label;
      }
    }
  }
}