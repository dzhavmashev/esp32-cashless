// Function : FUN_4010242c
// Address  : 0x4010242c
// Size     : 427 bytes


/* WARNING: Removing unreachable block (ram,0x401024f6) */
/* WARNING: Removing unreachable block (ram,0x40102530) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_4010242c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int *param_5,
            undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  byte local_44 [16];
  byte local_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40102184(param_1,param_2);
  uVar4 = 0xffffffff;
  if (iVar1 != 0) {
    (*(code *)&SUB_4008b530)(local_44,0,0x10);
    uVar6 = 0;
    for (piVar2 = param_5; piVar2 != param_5 + param_3; piVar2 = piVar2 + 1) {
      uVar6 = uVar6 + *piVar2;
    }
    iVar5 = 0;
    pbVar3 = (byte *)*param_4 + *param_5;
    pbVar7 = (byte *)*param_4;
    for (uVar10 = uVar6; 0xf < uVar10; uVar10 = uVar10 - 0x10) {
      pbVar8 = pbVar7 + 1;
      local_44[0] = local_44[0] ^ *pbVar7;
      memw();
      if (pbVar3 <= pbVar8) {
        iVar5 = iVar5 + 1;
        pbVar8 = (byte *)param_4[iVar5];
        pbVar3 = pbVar8 + param_5[iVar5];
      }
      if (uVar10 != 0x10) {
        memw();
        FUN_401021b8(iVar1,local_44);
      }
      pbVar7 = pbVar8;
    }
    uVar10 = uVar6 & 0xf;
    memw();
    (*(code *)&SUB_4008b530)(local_34,0,0x10);
    FUN_401021b8(iVar1,local_34);
    FUN_40184f28(local_34);
    if ((uVar10 != 0) || (uVar6 == 0)) {
      uVar6 = 0;
      while (uVar6 != uVar10) {
        pbVar9 = local_44 + uVar6;
        pbVar8 = pbVar7 + 1;
        uVar6 = uVar6 + 1;
        *pbVar9 = *pbVar9 ^ *pbVar7;
        memw();
        pbVar7 = pbVar8;
        if (pbVar3 <= pbVar8) {
          if (uVar6 == uVar10) break;
          iVar5 = iVar5 + 1;
          pbVar7 = (byte *)param_4[iVar5];
          pbVar3 = pbVar7 + param_5[iVar5];
        }
      }
      local_44[uVar10] = local_44[uVar10] ^ 0x80;
      memw();
      memw();
      FUN_40184f28(local_34);
    }
    local_34[0] = local_44[0] ^ local_34[0];
    memw();
    memw();
    FUN_401021b8(iVar1,local_34,param_6);
    FUN_401021d0(iVar1);
    uVar4 = 0;
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return uVar4;
}

