// Function : FUN_40154e34
// Address  : 0x40154e34
// Size     : 311 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40154e34(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined1 uVar8;
  uint uVar9;
  bool bVar10;
  uint uVar11;
  undefined1 local_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  byte bStack_3d;
  byte bStack_3c;
  undefined1 uStack_3b;
  int iStack_30;
  
  iVar1 = _DAT_3ffc8800;
  if ((param_2 != 0 && param_1 != 0) &&
     (uVar5 = (int)(*(byte *)(param_2 + 1) - 3) / 3 & 0xff, uVar5 < 2)) {
    iStack_30 = _DAT_3ffbfc54;
    memw();
    (*(code *)&SUB_4008b530)(&local_40,0,0xc);
    iVar2 = iStack_30;
    local_40 = *(undefined1 *)(param_2 + 2);
    memw();
    uStack_3f = *(undefined1 *)(param_2 + 3);
    memw();
    uStack_3e = *(undefined1 *)(param_2 + 4);
    uVar11 = (uint)bStack_3d;
    memw();
    uVar9 = (uint)bStack_3c;
    memw();
    bVar4 = false;
    bVar7 = false;
    bVar10 = false;
    uVar6 = 0;
    uVar8 = uStack_3b;
    while (uVar6 < uVar5) {
      uVar6 = (uint)*(byte *)(param_2 + 5);
      if ((uVar6 < 0xf) && (*(byte *)(param_2 + 6) + uVar6 < 0x10)) {
        bVar7 = true;
        uVar8 = *(undefined1 *)(param_2 + 7);
        bVar10 = true;
        bVar4 = true;
        uVar9 = (uint)*(byte *)(param_2 + 6);
        uVar11 = uVar6;
      }
      uVar6 = 1;
    }
    if (bVar4) {
      bStack_3d = (byte)uVar11;
      memw();
    }
    if (bVar10) {
      bStack_3c = (byte)uVar9;
      memw();
    }
    if (bVar7) {
      memw();
      uStack_3b = uVar8;
    }
    if (bStack_3d != 0) {
      if ((*(int *)(iStack_30 + 0x490) == 0) && ((*(int *)(iVar1 + 0x98) - 3U & 0xfffffffd) == 0)) {
        memw();
        iVar3 = (*(code *)&SUB_4008b33c)(iStack_30 + 0x488,&local_40,0xc);
        if (iVar3 != 0) {
          FUN_40154e0c();
        }
      }
      iVar3 = (*(code *)&SUB_4008b33c)(param_1,&local_40,0xc);
      if (iVar3 != 0) {
        (*(code *)&SUB_4008b3d0)(param_1,&local_40,0xc);
        DAT_3ffc8a04 = 1;
        memw();
        if ((*(int *)(iVar2 + 0x490) != 1) && ((*(int *)(iVar1 + 0x98) - 3U & 0xfffffffd) == 0)) {
          memw();
          FUN_40154e0c();
        }
      }
      return 1;
    }
  }
  return 0;
}

