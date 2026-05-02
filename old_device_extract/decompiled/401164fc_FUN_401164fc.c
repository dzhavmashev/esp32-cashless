// Function : FUN_401164fc
// Address  : 0x401164fc
// Size     : 79 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_401164fc(int *param_1,uint *param_2)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = -6;
  if (((*param_2 & 0xf0) == 0xe0) && (piVar2 = _DAT_3ffc83fc, *param_2 != _DAT_3ffc6480)) {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if ((((*(byte *)((int)piVar2 + 0xeb) & 0x20) != 0) &&
          (((param_1 == (int *)0x0 || (*param_1 == 0)) || (*param_1 == piVar2[1])))) &&
         (cVar1 = FUN_40116480(piVar2,param_2), cVar1 != '\0')) {
        return cVar1;
      }
    }
  }
  return cVar1;
}

