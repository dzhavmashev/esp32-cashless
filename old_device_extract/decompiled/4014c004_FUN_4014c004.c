// Function : FUN_4014c004
// Address  : 0x4014c004
// Size     : 257 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014c004(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint local_40 [4];
  uint uStack_30;
  
  *(int *)(*(int *)(param_2 + 4) + 4) = *(int *)(*(int *)(param_2 + 4) + 4) + 0xe;
  *(short *)(param_2 + 0x16) = *(short *)(param_2 + 0x16) + -0xe;
  memw();
  while( true ) {
    memw();
    iVar2 = FUN_4014bf94(param_2,local_40);
    if ((iVar2 == 0) || (iVar2 = FUN_4015fb34(0,7,local_40[0]), iVar2 == 0)) break;
    **(uint **)(iVar2 + 0x2c) = **(uint **)(iVar2 + 0x2c) | 0x80;
    memw();
    (*(code *)&SUB_4008b3d0)
              (*(undefined4 *)(*(int *)(iVar2 + 4) + 4),*(undefined4 *)(*(int *)(param_2 + 4) + 4),
               local_40[0]);
    if (_DAT_3ffc8800 == param_1) {
      if (_DAT_3ffc7a88 != (code *)0x0) {
        uVar6 = *(undefined4 *)(*(int *)(iVar2 + 4) + 4);
        pcVar4 = _DAT_3ffc7a88;
        goto LAB_4014c0b5;
      }
    }
    else {
      if (_DAT_3ffc7960 == (code *)0x0) goto LAB_4014c0b8;
      pbVar3 = *(byte **)(*(int *)(iVar2 + 4) + 4);
      uVar5 = local_40[0];
      if ((*pbVar3 & 1) == 0) {
        uStack_30 = local_40[0];
        memw();
        iVar7 = (*(code *)&SUB_4008b33c)(pbVar3,&DAT_3ffc89f8,6);
        uVar5 = uStack_30;
        if (iVar7 != 0) goto LAB_4014c09d;
      }
      else {
LAB_4014c09d:
        FUN_40153064(1,pbVar3,uVar5 & 0xffff);
      }
      uVar6 = *(undefined4 *)(*(int *)(iVar2 + 4) + 4);
      pcVar4 = _DAT_3ffc7960;
LAB_4014c0b5:
      (*pcVar4)(uVar6,local_40[0] & 0xffff,iVar2);
    }
LAB_4014c0b8:
    iVar7 = *(int *)(param_2 + 4);
    iVar2 = *(int *)(iVar7 + 4) + local_40[0];
    uVar1 = *(ushort *)(param_2 + 0x16);
    uVar5 = (uint)uVar1 - (local_40[0] & 0xffff);
    *(int *)(iVar7 + 4) = iVar2;
    *(short *)(param_2 + 0x16) = (short)uVar5;
    memw();
    if ((uVar5 & 0xffff) < 0x16) break;
    *(uint *)(iVar7 + 4) = iVar2 + ((local_40[0] + 3 & 0xfffffffc) - local_40[0]);
    *(ushort *)(param_2 + 0x16) = uVar1 - ((short)local_40[0] + 3U & 0xfffc);
    memw();
    memw();
  }
  FUN_4015fb50(param_2);
  return 0;
}

