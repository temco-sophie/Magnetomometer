int checkMetal(double cvVal,double ref_cv,double *cvVal_all) {
	int metal_stat;
	if ( (cvVal >= ref_cv) && (*(cvVal_all+4)>*(cvVal_all+3)) ) {
    	metal_stat=1; //CONTAMINATED BOX--METAL DETECTED
    }
	else {
    	metal_stat=0; //CLEAN BOX-- NO METAL PRESENT
	}
	return metal_stat;	
}
