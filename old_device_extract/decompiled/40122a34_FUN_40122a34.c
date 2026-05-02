// Function : FUN_40122a34
// Address  : 0x40122a34
// Size     : 311 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40122a34(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int aiStack_24 [9];
  
  aiStack_24[0] = 0x14;
  if (param_1 == (undefined4 *)0x0) {
    memw();
    uVar1 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc0e40,uVar1,0x3ffc16cf,"lf_pass",0x241);
    return 0x102;
  }
  _DAT_3ffc72dc = 0;
  memw();
  memw();
  _DAT_3ffc72e8 = param_1;
  iVar2 = FUN_401224e0();
  if (iVar2 < 0) {
    return iVar2;
  }
  aiStack_24[0] = aiStack_24[0] + iVar2;
  if ((code *)*param_1 != (code *)0x0) {
    memw();
    iVar2 = (*(code *)*param_1)(param_1[4],aiStack_24);
    if (iVar2 != 0) {
      uVar1 = (*(code *)&SUB_40094ae8)();
      uVar3 = 0x3ffc0e0a;
      goto LAB_40122aa2;
    }
  }
  if (((code *)param_1[1] == (code *)0x0) || (iVar2 = (*(code *)param_1[1])(param_1[4]), iVar2 == 0)
     ) {
    _DAT_3ffc7280 = aiStack_24[0];
    memw();
    _DAT_3ffc7284 = FUN_4018568c();
    _DAT_3ffc7288 = 0;
    _DAT_3ffc728c = 0;
    _DAT_3ffc7290 = 0;
    memw();
    iVar2 = (*(code *)param_1[2])(param_1[4],&DAT_3ffc7280,0x14);
    if (iVar2 == 0) {
      _DAT_3ffc72dc = 1;
      memw();
      _DAT_3ffc72e0 = (uint)_DAT_3ffc72e4 * 0x20 + 0x34;
      memw();
      iVar2 = FUN_401224e0();
      if (iVar2 < 0) {
        return iVar2;
      }
      _DAT_3ffc72dc = 2;
      memw();
      _DAT_3ffc72e0 = (uint)_DAT_3ffc72e4 * 0x20 + 0x34;
      memw();
      iVar2 = FUN_401224e0();
      if (iVar2 < 0) {
        return iVar2;
      }
      if ((code *)param_1[3] == (code *)0x0) {
        return 0;
      }
      iVar2 = (*(code *)param_1[3])(param_1[4]);
      if (iVar2 == 0) {
        return 0;
      }
      uVar1 = (*(code *)&SUB_40094ae8)();
      uVar3 = 0x3ffc0d81;
    }
    else {
      uVar1 = (*(code *)&SUB_40094ae8)();
      uVar3 = 0x3ffc0dab;
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094ae8)();
    uVar3 = 0x3ffc0dde;
  }
LAB_40122aa2:
  (*(code *)&SUB_40007d54)(uVar3,uVar1,0x3ffc16cf,iVar2);
  return iVar2;
}

