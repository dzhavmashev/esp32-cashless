// Function : FUN_40121fa0
// Address  : 0x40121fa0
// Size     : 143 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40121fa0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&SUB_4005cfec)(0,&DAT_3ffc7250,0xc);
  if (_DAT_3ffc725c == iVar1) {
    if ((_DAT_3ffc7250 == 0) || (_DAT_3ffc7254 < 4)) {
      uVar2 = (*(code *)&SUB_40094ae8)();
      (*(code *)&SUB_40007d54)(0x3ffc0ba0,uVar2,0x3ffc0d6d);
    }
    else {
      (*(code *)&SUB_40081fcc)(0x3ffc07c4);
      FUN_400f9220(1);
      _DAT_3ffc723c = 0x40121bc0;
      _DAT_3ffc7240 = 0x40121bb0;
      _DAT_3ffc7248 = &DAT_40121e6c;
      _DAT_3ffc7244 = &DAT_40121d40;
      _DAT_3ffc724c = 0x3ffc7210;
      memw();
      FUN_4012199c(param_1);
    }
  }
  else {
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc0bcc,uVar2,0x3ffc0d6d,iVar1,_DAT_3ffc725c);
  }
  return;
}

