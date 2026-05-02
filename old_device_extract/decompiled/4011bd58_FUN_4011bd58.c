// Function : FUN_4011bd58
// Address  : 0x4011bd58
// Size     : 424 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4011bd58(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  
  if (param_1 == 0) {
    return 0xf0;
  }
  _DAT_3ffc654c = param_1;
  if (*(int *)(param_1 + 0xd4) != 0) {
    memw();
    FUN_40113ef0();
  }
  iVar7 = _DAT_3ffc654c;
  uVar1 = FUN_40113f2c();
  iVar2 = _DAT_3ffc654c;
  *(undefined4 *)(iVar7 + 0xd4) = uVar1;
  iVar7 = *(int *)(iVar2 + 0xd4);
  if ((iVar7 == 0) || (param_2 == 0)) {
    pcVar8 = "egister";
LAB_4011bd94:
    memw();
    FUN_40174130(pcVar8);
    return 0xf0;
  }
  _DAT_3ffc6548 = 0xffffffff;
  memw();
  _DAT_3ffc6544 = param_2;
  iVar2 = FUN_40109eec(_DAT_3ffbe0e0);
  uVar3 = FUN_40109eec(_DAT_3ffbe0e0);
  pcVar8 = "ain pcb";
  if ((iVar2 - 1U | uVar3) != 0xffffffff) goto LAB_4011bd94;
  memw();
  uVar3 = FUN_40109eec(param_2);
  uVar4 = FUN_40109eec(_DAT_3ffbe0e0);
  uVar5 = FUN_40109eec(_DAT_3ffbe0e0);
  memw();
  uVar6 = FUN_40109eec(param_2);
  if ((uVar6 == (uVar5 ^ 0xffffffff | uVar3 & uVar4)) ||
     (uVar6 = FUN_40109eec(param_2), uVar5 = _DAT_3ffc6544, uVar6 == (uVar3 & uVar4))) {
    pcVar8 = "t mask.";
    goto LAB_4011bd94;
  }
  if (DAT_3ffc6524 != '\0') {
    memw();
    uVar3 = FUN_40109eec(_DAT_3ffc6544);
    uVar4 = FUN_40109eec(_DAT_3ffc6528);
    memw();
    uVar6 = FUN_40109eec(_DAT_3ffc652c);
    if ((((uVar3 < uVar4) || (uVar6 < uVar3)) &&
        (((_DAT_3ffc6544 ^ _DAT_3ffc6528 | _DAT_3ffc6544 ^ _DAT_3ffc652c) & _DAT_3ffbe0e0) == 0)) &&
       ((uVar6 + 1) - uVar4 < 0x65)) {
      if (DAT_3ffc6524 != '\0') goto LAB_4011bee1;
    }
    else {
      _DAT_3ffc6524 = _DAT_3ffc6524 & 0xffffff00;
      memw();
    }
  }
  memw();
  uVar5 = FUN_40109eec(uVar5);
  uVar4 = FUN_40109eec(_DAT_3ffbe0e0);
  uVar4 = uVar5 & uVar4;
  uVar3 = FUN_40109eec(_DAT_3ffbe0e0);
  uVar6 = uVar3 ^ 0xffffffff | uVar4;
  uVar3 = uVar5;
  if (uVar5 - uVar4 <= uVar6 - uVar5) {
    uVar3 = uVar6;
    uVar4 = uVar5;
  }
  _DAT_3ffc6528 = uVar4 + 1;
  _DAT_3ffc652c = uVar3 - 1;
  if (100 < uVar3 - _DAT_3ffc6528) {
    _DAT_3ffc652c = uVar4 + 100;
  }
  _DAT_3ffc6524 = 0;
  memw();
  _DAT_3ffc6528 = FUN_40109eec();
  memw();
  _DAT_3ffc652c = FUN_40109eec(_DAT_3ffc652c);
  _DAT_3ffc6524 = CONCAT31(DAT_3ffc6524_1,1);
  memw();
  memw();
LAB_4011bee1:
  _DAT_3ffc6538 = _DAT_3ffc6528;
  memw();
  FUN_40113770(iVar7,param_1 + 4,0x43);
  FUN_40185408(iVar7,0x4011b804,0);
  return 0;
}

