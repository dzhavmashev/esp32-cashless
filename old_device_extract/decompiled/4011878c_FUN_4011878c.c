// Function : FUN_4011878c
// Address  : 0x4011878c
// Size     : 69 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_4011878c(int *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  
  cVar1 = -6;
  piVar3 = (int *)_DAT_3ffc83fc;
  do {
    if (piVar3 == (int *)0x0) {
      return cVar1;
    }
    if (((param_1 == (int *)0x0) ||
        ((((*param_1 == 0 && (param_1[1] == 0)) && (param_1[2] == 0)) && (param_1[3] == 0)))) ||
       (uVar2 = FUN_4010b8c0(piVar3,param_1), (uVar2 & 0x80) == 0)) {
      cVar1 = FUN_4011869c(piVar3,param_2);
      if (cVar1 != '\0') {
        return cVar1;
      }
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}

