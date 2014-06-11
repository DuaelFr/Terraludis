<?php
/**
 * @file
 * Global hooks for terraludis profile.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function terraludis_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['#access'] = FALSE;
  $form['server_settings']['#access'] = FALSE;
  $form['update_notifications']['#access'] = FALSE;
}
