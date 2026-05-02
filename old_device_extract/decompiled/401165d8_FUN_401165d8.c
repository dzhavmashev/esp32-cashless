// Function : FUN_401165d8
// Address  : 0x401165d8
// Size     : 84 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_401165d8(int *param_1,uint *param_2)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  
  cVar2 = -6;
  if (((*param_2 & 0xf0) == 0xe0) && (cVar2 = -6, *param_2 != _DAT_3ffc6480)) {
    cVar2 = -6;
    for (piVar3 = (int *)_DAT_3ffc83fc; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      if (((*(byte *)((int)piVar3 + 0xeb) & 0x20) != 0) &&
         (((param_1 == (int *)0x0 || (*param_1 == 0)) || (*param_1 == piVar3[1])))) {
        cVar1 = FUN_4011654c(piVar3,param_2);
        if (cVar2 != '\0') {
          cVar2 = cVar1;
        }
      }
    }
  }
  return cVar2;
}

