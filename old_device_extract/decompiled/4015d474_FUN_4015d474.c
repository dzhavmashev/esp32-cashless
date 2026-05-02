// Function : FUN_4015d474
// Address  : 0x4015d474
// Size     : 113 bytes


void FUN_4015d474(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  
  DAT_3ffc88ed = (undefined1)param_2;
  *(undefined1 *)(param_1 + 0xa6) = DAT_3ffc88ed;
  memw();
  cVar1 = *(char *)(param_1 + 0xa4);
  if (param_3 != 0) {
    if (cVar1 == '\0') goto LAB_4015d4d1;
    param_2 = cVar1 * 0xd + param_2 * 3;
    if (param_2 < 0) {
      param_2 = param_2 + 0xf;
    }
    param_2 = param_2 >> 4;
  }
  if (cVar1 != '\0') {
    if (*(char *)(param_1 + 0xa5) == '\0') {
      cVar1 = (char)param_2 - cVar1;
      memw();
    }
    else {
      uVar2 = (param_2 - cVar1) * 6 + *(char *)(param_1 + 0xa5) * 10;
      if ((int)uVar2 < 0) {
        uVar2 = uVar2 + 0xf;
      }
      cVar1 = (char)(uVar2 >> 4);
    }
    *(char *)(param_1 + 0xa5) = cVar1;
  }
LAB_4015d4d1:
  *(char *)(param_1 + 0xa4) = (char)param_2;
  memw();
  memw();
  memw();
  return;
}

