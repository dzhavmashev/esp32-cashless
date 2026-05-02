// Function : FUN_4014ce0c
// Address  : 0x4014ce0c
// Size     : 260 bytes


uint FUN_4014ce0c(int param_1)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined1 local_30 [48];
  
  iVar4 = *(int *)(param_1 + 0x34);
  local_30[0] = 0;
  memw();
  if ((iVar4 != 0) && (*(short *)(iVar4 + 6) == 1)) {
    iVar6 = iVar4 + 0xe;
    iVar3 = *(byte *)(iVar4 + 1) - 0xc;
    DAT_3ffc89ec = 3;
    memw();
    memw();
    DAT_3ffc89f0 = FUN_4014c194(iVar4 + 8,local_30);
    uVar5 = 0;
    memw();
    uVar1 = *(ushort *)(iVar4 + 0xc);
    memw();
    for (; 0 < iVar3; iVar3 = iVar3 + -4) {
      if (uVar1 <= uVar5) {
        memw();
        iVar4 = (uint)uVar1 * 4 + iVar4;
        uVar8 = iVar3 - 2;
        uVar5 = 0;
        piVar7 = (int *)(iVar4 + 0x10);
        while( true ) {
          if ((int)uVar8 < 1) {
            return (uVar8 ^ 0xffffffff) >> 0x1f;
          }
          if (*(ushort *)(iVar4 + 0xe) <= uVar5) break;
          if (*piVar7 == 0x1f25000) {
            DAT_3ffc89ed = 2;
            memw();
            memw();
          }
          else if (*piVar7 == 0x2f25000) {
            DAT_3ffc89ed = 3;
            memw();
          }
          piVar7 = piVar7 + 1;
          uVar8 = uVar8 - 4;
          uVar5 = uVar5 + 1;
        }
        memw();
        return 1;
      }
      bVar2 = FUN_4014c194(iVar6,local_30);
      if (DAT_3ffc89ee < 2) {
        memw();
        DAT_3ffc89ee = bVar2;
      }
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    }
  }
  memw();
  return 0;
}

