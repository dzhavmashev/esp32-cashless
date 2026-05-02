// Function : FUN_40101e2c
// Address  : 0x40101e2c
// Size     : 147 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40101e2c(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *apiStack_24 [9];
  
  if (_DAT_3ffc5884 == 0) {
    return 0xffffffff;
  }
  pcVar2 = (char *)(_DAT_3ffc5884 + param_1 + 0xf7);
  (*(code *)&SUB_4009019c)(_DAT_3ffc5888,0xffffffff);
  if (*pcVar2 == '\0') {
    apiStack_24[0] = (int *)(*(code *)&SUB_40094d60)(8);
    uVar3 = _DAT_3ffc5888;
    if (apiStack_24[0] == (int *)0x0) {
      memw();
      (*(code *)&SUB_4008fc8c)();
    }
    else {
      *pcVar2 = '\x01';
      memw();
      memw();
      (*(code *)&SUB_4008fc8c)(uVar3);
      *apiStack_24[0] = param_1;
      uVar3 = _DAT_3ffc587c;
      apiStack_24[0][1] = param_2;
      memw();
      iVar1 = (*(code *)&SUB_4008fab8)(uVar3,apiStack_24,10,0);
      if (iVar1 == 1) {
        if (_DAT_3ffc5874 != 0) {
          (*(code *)&SUB_40090010)(_DAT_3ffc5874,0xffffffff);
        }
        goto LAB_40101e5a;
      }
    }
    uVar3 = 0xffffffff;
  }
  else {
    (*(code *)&SUB_4008fc8c)(_DAT_3ffc5888);
LAB_40101e5a:
    uVar3 = 0;
  }
  return uVar3;
}

