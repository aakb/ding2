Feature: Creation of facet campaigns
  In order to create facet campaigns in DDB CMS
  As an editor
  I want to create campaigns and verify that they are triggered correctly when users
  browse and search the site

  Background:
    Given I am logged in as a cms user with the administrators role
    When I go to the create campaign plus page
    And I fill a campaign with the following:
      | Title | Behatman & Robin       |
      | Type  | Text only              |
      | Text  | Bats 4ever             |
      | Link  | <front>                |
      | Style | Boks                   |
      | Tags  | campaign, super heroes |

  @api @campaign_plus @regression @cci
  Scenario: Create a 'facet' campaign and show it on subject search result
    When I add a facet trigger with the following:
      | Facet type   | Emne |
      | Facet value  | Børn |
      | Common value | 7    |
    And I save the campaign
    And I have searched for "term.subject=børn"
    Then "Behatman & Robin" should appear within 2 seconds
    And "Bats 4ever" should appear within 2 seconds
    Given I have searched for "term.subject=biler"
    Then "Behatman & Robin" should not appear within 2 seconds

  @api @campaign_plus @regression @cci
  Scenario: Create a 'facet' campaign and show it on material type search result
    When I add a facet trigger with the following:
      | Facet type   | Materialetype |
      | Facet value  | bog           |
      | Common value | 1             |
    And I save the campaign
    And I have searched for "term.subject=film"
    Then "Behatman & Robin" should not appear within 2 seconds

  @api @campaign_plus @regression @cci
  Scenario: Create a 'facet' campaign and show it on material type search result
    When I add a facet trigger with the following:
      | Facet type   | Forlag    |
      | Facet value  | gyldendal |
      | Common value | 1         |
    And I save the campaign
    And I have searched for "facet.publisher=gyldendal"
    Then "Behatman & Robin" should appear within 2 seconds
    And I have searched for "facet.publisher=systime"
    Then "Behatman & Robin" should not appear within 2 seconds