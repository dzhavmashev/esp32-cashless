// Function : FUN_4015ef10
// Address  : 0x4015ef10
// Size     : 148 bytes


undefined4 FUN_4015ef10(int param_1,int param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  pbVar2 = (byte *)(*(int *)(*(int *)(param_2 + 4) + 4) + param_3);
  if ((pbVar2[3] & 0x20) != 0) {
    uVar1 = FUN_40186998();
    iVar6 = (uVar1 & 0xffff) * 8 + param_1;
    uVar4 = (uint)pbVar2[1] << 8 | (uint)pbVar2[4] << 0x10 | (uint)*pbVar2 | (uint)pbVar2[5] << 0x18
    ;
    uVar5 = (uint)*(ushort *)(pbVar2 + 6);
    uVar1 = *(uint *)(iVar6 + 8);
    uVar7 = *(uint *)(iVar6 + 0xc);
    if (((uVar1 == 0xffffffff) && (uVar7 == 0xffffffff)) ||
       (((uVar1 != uVar4 || (uVar7 != uVar5)) &&
        (((uVar5 - uVar7) - (uint)(uVar4 < uVar4 - uVar1) & 0x8000) == 0)))) {
      *(uint *)(iVar6 + 8) = uVar4;
      *(uint *)(iVar6 + 0xc) = uVar5;
      iVar3 = *(int *)(param_1 + 0xa0);
      iVar6 = *(int *)(iVar3 + 4);
      *(int *)(*(int *)(param_2 + 4) + 4) = *(int *)(*(int *)(param_2 + 4) + 4) + param_3 + iVar6;
      *(short *)(param_2 + 0x16) =
           *(short *)(param_2 + 0x16) - ((short)*(undefined4 *)(iVar3 + 8) + (short)iVar6);
      memw();
      memw();
      return 1;
    }
  }
  return 0;
}

