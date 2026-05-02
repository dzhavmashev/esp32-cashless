// Function : FUN_4018adc0
// Address  : 0x4018adc0
// Size     : 127 bytes


void FUN_4018adc0(int param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  
  if ((-1 < *(char *)(param_1 + 0xb)) && ((*(uint *)(param_1 + 0x18) & 0x100) == 0)) {
    cVar3 = *param_2 + DAT_3ffc072a;
    if (*(char *)(param_1 + 2) == 0x7f) {
      *(char *)(param_1 + 2) = cVar3;
      memw();
      cVar2 = '\0';
    }
    else {
      cVar2 = (char)((uint)((int)*(char *)(param_1 + 2) + (int)cVar3) >> 1);
      *(char *)(param_1 + 2) = cVar3;
      memw();
      memw();
      cVar3 = cVar2;
    }
    if (*(char *)(param_1 + 3) != 0x7f) {
      iVar1 = *(char *)(param_1 + 3) * 3 + (int)cVar2;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 3;
      }
      *(char *)(param_1 + 3) = (char)(iVar1 >> 2);
      memw();
      memw();
      return;
    }
    *(char *)(param_1 + 3) = cVar3;
    memw();
  }
  memw();
  return;
}

