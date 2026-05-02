// Function : FUN_40122194
// Address  : 0x40122194
// Size     : 341 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40122194(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  
  if (param_3 == 0) {
    uVar1 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc14b9,uVar1,0x3ffc16cf,"te_note",0xfd);
    return -3;
  }
  (*(code *)&SUB_4008b530)(&uStack_2c,0,0xc);
  iVar2 = (*(code *)&SUB_4008c01c)(param_1);
  if (0x20 < iVar2 + 1U) {
    uVar1 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc158f,uVar1,0x3ffc16cf,"segment",0xd7,iVar2 + 1U);
    iVar2 = 0;
    goto LAB_401221f4;
  }
  uVar4 = param_4 + 3U & 0xfffffffc;
  uVar5 = iVar2 + 4U & 0xfffffffc;
  iVar2 = uVar4 + 0xc + uVar5;
  if (_DAT_3ffc72dc == 2) {
    memw();
    (*(code *)&SUB_4008b3d0)(0x3ffc7260,param_1,uVar5);
    memw();
    uStack_2c = uVar5;
    iStack_28 = param_4;
    uStack_24 = param_2;
    iVar3 = (**(code **)(_DAT_3ffc72e8 + 8))(*(undefined4 *)(_DAT_3ffc72e8 + 0x10),&uStack_2c,0xc);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(_DAT_3ffc72e8 + 8))
                        (*(undefined4 *)(_DAT_3ffc72e8 + 0x10),0x3ffc7260,uVar5);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(_DAT_3ffc72e8 + 8))
                          (*(undefined4 *)(_DAT_3ffc72e8 + 0x10),param_3,uVar4);
        if (iVar3 == 0) goto LAB_401222e1;
        uVar1 = (*(code *)&SUB_40094ae8)();
        uVar7 = 0xef;
        uVar6 = 0x3ffc14ee;
      }
      else {
        uVar1 = (*(code *)&SUB_40094ae8)();
        uVar7 = 0xeb;
        uVar6 = 0x3ffc1523;
      }
    }
    else {
      uVar1 = (*(code *)&SUB_40094ae8)();
      uVar7 = 0xe7;
      uVar6 = 0x3ffc1558;
    }
    (*(code *)&SUB_40007d54)(uVar6,uVar1,0x3ffc16cf,"segment",uVar7,iVar3);
    iVar2 = -2;
  }
  else {
LAB_401222e1:
    if (0 < iVar2) {
      return iVar2;
    }
  }
LAB_401221f4:
  uVar1 = (*(code *)&SUB_40094ae8)();
  (*(code *)&SUB_40007d54)(0x3ffc147a,uVar1,0x3ffc16cf,"te_note",0x101,iVar2);
  return iVar2;
}

