// Function : FUN_40122370
// Address  : 0x40122370
// Size     : 222 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_40122370(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_40 [2];
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  
  (*(code *)&SUB_4008b530)(local_40,0,0x20);
  if (param_2 == 0) {
    uVar1 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc1635,uVar1,0x3ffc16cf,"er_data",0xa7);
    uVar2 = 0xfffffffd;
  }
  else {
    uVar4 = param_3 + 3U & 0xfffffffc;
    local_40[0] = (uint)_DAT_3ffc72dc;
    if (local_40[0] == 0) {
      _DAT_3ffc72e4 = _DAT_3ffc72e4 + 1;
      memw();
      uVar2 = uVar4 + 0x20;
      memw();
    }
    else {
      if (local_40[0] == 1) {
        uStack_28 = 6;
        memw();
        uStack_38 = param_1;
        uStack_34 = param_1;
        uStack_30 = uVar4;
        uStack_2c = uVar4;
        uVar2 = FUN_4012232c(local_40);
        if ((int)uVar2 < 1) {
          uVar1 = (*(code *)&SUB_40094ae8)();
          (*(code *)&SUB_40007d54)(0x3ffc15fd,uVar1,0x3ffc16cf,"er_data",0xb8,uVar2);
          return uVar2;
        }
      }
      else {
        iVar3 = (**(code **)(_DAT_3ffc72e8 + 8))
                          (*(undefined4 *)(_DAT_3ffc72e8 + 0x10),param_2,uVar4);
        uVar2 = uVar4;
        if (iVar3 != 0) {
          uVar1 = (*(code *)&SUB_40094ae8)();
          (*(code *)&SUB_40007d54)(0x3ffc15c5,uVar1,0x3ffc16cf,"er_data",0xc2,iVar3);
          return 0xfffffffe;
        }
      }
      _DAT_3ffc72e0 = _DAT_3ffc72e0 + uVar4;
      memw();
    }
  }
  return uVar2;
}

