// Function : FUN_4010d578
// Address  : 0x4010d578
// Size     : 116 bytes


void FUN_4010d578(int *param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) goto LAB_4010d5d9;
  piVar3 = (int *)(*(code *)&SUB_40094c54)(" LISTEN",0x961,"tw_pcbs","en-pcbs");
  do {
    param_2 = (int *)piVar3[0xd];
    if ((char)param_1[5] == (char)piVar3[5]) {
      if ((char)param_1[5] == '\x06') {
        bVar2 = false;
        bVar1 = false;
        if ((((*param_1 == *piVar3) && (bVar1 = bVar2, piVar3[1] == param_1[1])) &&
            (piVar3[2] == param_1[2])) && (piVar3[3] == param_1[3])) {
          bVar1 = (char)piVar3[4] == (char)param_1[4];
        }
      }
      else {
        bVar1 = *param_1 == *piVar3;
      }
      if (bVar1) {
        FUN_4010d4dc();
      }
    }
LAB_4010d5d9:
    piVar3 = param_2;
  } while (param_2 != (int *)0x0);
  return;
}

