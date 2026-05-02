// Function : FUN_400f3384
// Address  : 0x400f3384
// Size     : 97 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f3384(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  
  FUN_400f3354();
  (*(code *)&SUB_40090010)(_DAT_3ffc5548,0xffffffff);
  if (_DAT_3ffc554c != (int *)0x0) {
    piVar1 = _DAT_3ffc554c;
    if (param_1 == 0) {
      do {
        (*(code *)piVar1[3])(piVar1[2],0,param_2,param_3);
        piVar1 = (int *)piVar1[1];
      } while (piVar1 != (int *)0x0);
    }
    else {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)piVar2[1];
      } while ((int *)piVar2[1] != (int *)0x0);
      do {
        (*(code *)piVar2[3])(piVar2[2],1,param_2,param_3);
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)0x0);
    }
  }
  (*(code *)&SUB_4008fab8)(_DAT_3ffc5548,0,0);
  return;
}

