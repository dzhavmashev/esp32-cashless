// Function : FUN_401188a8
// Address  : 0x401188a8
// Size     : 74 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_401188a8(int *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  
  cVar4 = -6;
  for (piVar3 = (int *)_DAT_3ffc83fc; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    if (((param_1 == (int *)0x0) ||
        ((((*param_1 == 0 && (param_1[1] == 0)) && (param_1[2] == 0)) && (param_1[3] == 0)))) ||
       (uVar2 = FUN_4010b8c0(piVar3,param_1), (uVar2 & 0x80) == 0)) {
      cVar1 = FUN_401187d4(piVar3,param_2);
      if (cVar4 != '\0') {
        cVar4 = cVar1;
      }
    }
  }
  return cVar4;
}

