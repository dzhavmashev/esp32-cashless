// Function : FUN_40122454
// Address  : 0x40122454
// Size     : 136 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40122454(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_40 [4];
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  (*(code *)&SUB_4008b530)(local_40,0,0x20);
  if (_DAT_3ffc72dc == 1) {
    uStack_28 = 6;
    local_40[0] = 4;
    memw();
    iStack_30 = param_1;
    iStack_2c = param_1;
    iVar1 = FUN_4012232c(local_40);
    if (iVar1 < 1) {
      uVar2 = (*(code *)&SUB_40094ae8)();
      (*(code *)&SUB_40007d54)(0x3ffc1389,uVar2,0x3ffc16cf,"_header",0x164,iVar1);
      param_1 = iVar1;
    }
    else {
      _DAT_3ffc72e0 = _DAT_3ffc72e0 + param_1;
      param_1 = 0x20;
      memw();
    }
  }
  else if (_DAT_3ffc72dc == 0) {
    param_1 = param_1 + 0x20;
    _DAT_3ffc72e4 = _DAT_3ffc72e4 + 1;
    memw();
    memw();
  }
  else {
    _DAT_3ffc72e0 = _DAT_3ffc72e0 + param_1;
    memw();
  }
  return param_1;
}

