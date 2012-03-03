<?php
/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can modify or override Drupal's theme
 *   functions, intercept or make additional variables available to your theme,
 *   and create custom PHP logic. For more information, please visit the Theme
 *   Developer's Guide on Drupal.org: http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to STARTERKIT_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: STARTERKIT_breadcrumb()
 *
 *   where STARTERKIT is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override either of the two theme functions used in Zen
 *   core, you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/*function tl_ruban_feed_icon($url) {
  if ($image = theme('image', path_to_subtheme() . '/images/rss.png', t('Subscribe by RSS'), t('Subscribe by RSS'))) {
    return '<a href="'. check_url($url) .'" class="feed-icon">'. $image. '</a>';
  }
}*/
function tl_ruban_feed_icon($variables) {
  $text = t('Subscribe to @feed-title', array('@feed-title' => $variables['title']));
  if ($image = theme('image', array('path' => 'sites/terraludis.org/themes/tl_ruban/images/rss.png', 'width' => 20, 'height' => 20, 'alt' => $text))) {
    return l($image, $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-icon'), 'title' => $text)));
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // STARTERKIT_preprocess_node_page() or STARTERKIT_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  $variables['classes_array'][] = 'count-' . $variables['block_id'];
}
// */

/**
 * Themes a select element as a set of checkboxes
 *
 * @see theme_select(), http://api.drupal.org/api/function/theme_select/6
 * @param array $vars - An array of arrays, the 'element' item holds the properties of the element.
 *                      Properties used: title, value, options, description
 * @return HTML string representing the form element.
 */
function tl_ruban_select_as_checkboxes($vars) {
  $element = $vars['element'];
  if (!empty($element['#bef_nested'])) {
    if (empty($element['#attributes']['class'])) {
      $element['#attributes']['class'] = array();
    }
    $element['#attributes']['class'][] = 'form-checkboxes';
    return theme('select_as_tree', array('element' => $element));
  }

  // the selected keys from #options
  $selected_options = empty($element['#value']) ? $element['#default_value'] : $element['#value'];

  // Grab exposed filter description.  We'll put it under the label where it makes more sense.
  $description = '';
  if (!empty($element['#description'])) {
    $description = '<div class="description">'. $element['#description'] .'</div>';
    unset($element['#description']);
  }

  $output = '<div class="bef-checkboxes">';
  foreach ($element['#options'] as $option => $elem) {
    if ('All' === $option) {
      // TODO: 'All' text is customizable in Views
      // No need for an 'All' option -- either unchecking or checking all the checkboxes is equivalent
      continue;
    }

    // Check for Taxonomy-based filters
    if (is_object($elem)) {
      list($option, $elem) = each(array_slice($elem->option, 0, 1, TRUE));
    }

    /*
     * Check for optgroups.  Put subelements in the $element_set array and add a group heading.
     * Otherwise, just add the element to the set
     */
    $element_set = array();
    $is_optgroup = FALSE;
    if (is_array($elem)) {
      $output .= '<div class="bef-group">';
      $output .= '<div class="bef-group-heading">' . $option . '</div>';
      $output .= '<div class="bef-group-items">';
      $element_set = $elem;
      $is_optgroup = TRUE;
    }
    else {
      $element_set[$option] = $elem;
    }

    foreach ($element_set as $key => $value) {
      $output .= _tl_ruban_checkbox($element, $key, $value, array_search($key, $selected_options) !== FALSE);
    }

    if ($is_optgroup) {
      $output .= '</div></div>';    // Close group and item <div>s
    }

  }
  $output .= '</div>';

  // Fake theme_checkboxes() which we can't call because it calls theme_form_element() for each option
  $attributes['class'] = array('form-checkboxes', 'bef-select-as-checkboxes');
  if (!empty($element['#bef_select_all_none'])) {
    $attributes['class'][] = 'bef-select-all-none';
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($element['#attributes']['class'], $attributes['class']);
  }

  return '<div' . drupal_attributes($attributes) . ">$description$output</div>";
}

/**
 * Build a CUSTOM BEF checkbox -- very similar to theme_checkbox
 * (http://api.drupal.org/api/function/theme_checkbox/6)
 * Allow HTML label
 *
 * @param $element - array: original <select> element generated by Views
 * @param $value - string: value of this checkbox option
 * @param $label - string: label for this checkbox option
 * @param $selected - bool: checked or not
 * @return string: checkbox HTML
 */
function _tl_ruban_checkbox($element, $value, $label, $selected) {
  $value = check_plain($value);
//  $label = check_plain($label);
  $id = drupal_html_id($element['#id'] . '-' . $value);
  // Custom ID for each checkbox based on the <select>'s original ID
  $properties = array(
    '#required' => FALSE,
    '#id' => $id,
  );

  // Prevent the select-all-none class from cascading to all checkboxes
  if (!empty($element['#attributes']['class'])
      && FALSE !== ($key = array_search('bef-select-all-none', $element['#attributes']['class']))) {
    unset($element['#attributes']['class'][$key]);
  }

  $checkbox = '<input type="checkbox" '
    . 'name="' . $element['#name'] . '[]" '    // brackets are key -- just like select
    . 'id="' . $id . '" '
    . 'value="' . $value . '" '
    . ($selected ? 'checked="checked" ' : '')
    . drupal_attributes($element['#attributes']) . ' />';
  $properties['#children'] = "$checkbox <label class='option' for='$id'>$label</label>";
  $output = theme('form_element', array('element' => $properties));
  return $output;
}