#-----------------------------------------------------------------------------------
# Program to parse a .tbmspec file and for each Test Case of type External Task
# set the "Program" to the value of the Custom Attribute "Program"
#
# Create a new .tbmspec file which contains just the Test Cases of type Unit Test
# Remove any unnecessary tags etc and then update the documentation and description
# fields from the information found in the .tcf file
#
# Pre-requisites : Requires Python 2.7 or above
#
# Author : M.W.Richardson   
# Date   : 01/01/2018
# 
# Copyright (C) 2018 Liverpool Data Research Associates
#-----------------------------------------------------------------------------------
import sys
import xml.etree.ElementTree as ET

# Variables
# ---------
program = ''

# Create a log file
# -----------------
log = open('Set_External_Tasks.log','w')


if not len(sys.argv) == 3:
	log.write('Error: Incorrect number of arguments! Usage: ' + sys.argv[0] + ' project tbmspec file, tasks tbmspec file\n' )
	sys.exit(1)
  
project_tbmspec_file=sys.argv[1]
tasks_tbmspec_file=sys.argv[2]

tree = ET.parse(project_tbmspec_file)
root = tree.getroot()

for tc in root.findall('TestCase'):
  if (tc.get('type')=='External Task'):
    for attr in tc.findall('CustomAttribute'):
      if (attr.get('name') == 'Program'):
        program = attr.get('value')
        log.write ('program name = ' + program + '\n')    
       
    tc.set('program', program)
    
    # Remove all unnecessary elements
    # -------------------------------
    for tag in tc.findall('Tag'):
      tc.remove(tag)

    for art in tc.findall('Artifact'):
      tc.remove(art)

    for ass in tc.findall('Asset'):
      tc.remove(ass)

 
# Remove everything except the External Tasks
# -------------------------------------------
for tc in root.findall('TestCase'):
  if not (tc.get('type')=='External Task'):
    root.remove(tc)

for req in root.findall('Requirement'):
  root.remove(req)

for doc in root.findall('Document'):
  root.remove(doc)

for prg in root.findall('Program'):
  root.remove(prg)

for rol in root.findall('Role'):
  root.remove(rol)

for mac in root.findall('Macros'):
  root.remove(mac)

for grp in root.findall('GroupSpecification'):
  root.remove(grp)


# Finally write the new tbmpec that contains just the External Tasks
# ------------------------------------------------------------------
tree.write (tasks_tbmspec_file,encoding="UTF-8", xml_declaration=True)
