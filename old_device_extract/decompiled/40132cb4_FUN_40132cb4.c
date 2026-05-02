// Function : FUN_40132cb4
// Address  : 0x40132cb4
// Size     : 69 bytes


undefined4 FUN_40132cb4(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_1;
  if ((iVar2 == 0) || (((*(uint *)(iVar2 + 0x14) & 2) == 0 && (*(int *)(iVar2 + 8) != param_3)))) {
LAB_40132cc0:
    uVar3 = 0xffff9f00;
  }
  else {
    param_1[1] = param_3;
    param_1[2] = param_4;
    if ((param_4 == 1) || (*(int *)(iVar2 + 4) - 3U < 3)) {
      pcVar1 = *(code **)(*(int *)(iVar2 + 0x1c) + 0x1c);
    }
    else {
      if (param_4 != 0) goto LAB_40132cc0;
      pcVar1 = *(code **)(*(int *)(iVar2 + 0x1c) + 0x20);
    }
    memw();
    uVar3 = (*pcVar1)(param_1[0xf],param_2);
  }
  return uVar3;
}

