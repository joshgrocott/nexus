// ----------------------------------------------------------------------------
//  $Id: DefaultEventAction.cc 4383 2011-10-14 07:46:57Z paola $
//
//  Author : J Martin-Albo <jmalbos@ific.uv.es>
//  Created: 15 Apr 2009
//
//  Copyright (c) 2009-2011 NEXT Collaboration
// ----------------------------------------------------------------------------

#include "DefaultEventAction.h"

#include <G4Event.hh>
#include <G4VVisManager.hh>
#include <G4Trajectory.hh>


namespace nexus {
    
  
  DefaultEventAction::DefaultEventAction(): 
    _nevt(0), _nupdate(10)
  {
  }
  
  
  
  DefaultEventAction::~DefaultEventAction()
  {
  }
  
  
  
  void DefaultEventAction::BeginOfEventAction(const G4Event* event)
  {
    // Print out event number info
    if ((_nevt%_nupdate) == 0) {
      G4cout << " >> Event no. " << _nevt << G4endl;
      if (_nevt == (10*_nupdate))
	_nupdate *= 10;
    }
   
  }
  
  
  
  void DefaultEventAction::EndOfEventAction(const G4Event* event)
  {
    _nevt++;

    // draw tracks in visual mode
    if (G4VVisManager::GetConcreteInstance()) {
      G4TrajectoryContainer* tc = event->GetTrajectoryContainer();
      if (tc) {
     	for (size_t i=0; i<tc->size(); i++) {
	  G4Trajectory* trj = (G4Trajectory*) (*tc)[i];
	  trj->DrawTrajectory();
	}
      }
    }
  }
  

} // end namespace nexus