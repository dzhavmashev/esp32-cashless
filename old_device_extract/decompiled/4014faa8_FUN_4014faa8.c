// Function : FUN_4014faa8
// Address  : 0x4014faa8
// Size     : 326 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014faa8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = *(int *)(param_1 + 0x14);
  uVar2 = 0x102;
  if (iVar4 != 0) {
    bVar7 = *_DAT_3ffbfc54;
    (*(code *)&SUB_4008b530)(iVar4,0,0xb8);
    iVar1 = _DAT_3ffc8804;
    uVar2 = 0x3005;
    if ((1 < bVar7) && (uVar2 = 0x3007, _DAT_3ffc8804 != 0)) {
      (*(code *)&SUB_4008b530)(iVar4,0,0xb8);
      for (uVar5 = 1; uVar5 <= _DAT_3ffbfc54[0x3f6]; uVar5 = uVar5 + 1 & 0xff) {
        iVar3 = uVar5 * 4 + iVar1;
        iVar8 = *(int *)(iVar3 + 0xec);
        if ((iVar8 != 0) && (*(short *)(iVar8 + 0x26) != 0)) {
          (*(code *)&SUB_4008b3d0)(*(int *)(iVar4 + 0xb4) * 0xc + iVar4,iVar8 + 4,6);
          iVar9 = *(int *)(iVar4 + 0xb4);
          iVar8 = iVar9 * 0xc + iVar4;
          *(undefined1 *)(iVar8 + 6) = *(undefined1 *)(*(int *)(iVar3 + 0xec) + 0xa4);
          memw();
          bVar6 = *(byte *)(iVar8 + 7) & 0xef | (*(byte *)(*(int *)(iVar3 + 0xec) + 0x2f9) & 1) << 4
          ;
          *(byte *)(iVar8 + 7) = bVar6;
          memw();
          bVar7 = *(byte *)(*(int *)(iVar3 + 0xec) + 0x32);
          if (bVar7 == 2) {
            bVar6 = bVar6 | 1;
LAB_4014fb6a:
            *(byte *)(iVar8 + 7) = bVar6 | bVar7;
            memw();
            if (*(char *)(*(int *)(iVar3 + 0xec) + 0x28a) != '\0') {
              bVar6 = bVar6 | bVar7 | 8;
              memw();
LAB_4014fbb7:
              *(byte *)(iVar8 + 7) = bVar6;
              memw();
            }
          }
          else {
            if (bVar7 < 3) {
              if (bVar7 != 1) {
                memw();
                goto LAB_4014fbbd;
              }
              goto LAB_4014fb6a;
            }
            if (bVar7 == 3) {
              bVar7 = bVar6 | 7;
              *(byte *)(iVar8 + 7) = bVar7;
              memw();
              bVar6 = 8;
              if (*(char *)(*(int *)(iVar3 + 0xec) + 0x28a) == '\0') {
                memw();
                goto LAB_4014fbbd;
              }
LAB_4014fbb4:
              bVar6 = bVar6 | bVar7;
              goto LAB_4014fbb7;
            }
            if (bVar7 == 4) {
              bVar7 = 8;
              goto LAB_4014fbb4;
            }
          }
LAB_4014fbbd:
          *(int *)(iVar4 + 0xb4) = iVar9 + 1;
        }
        if ((int)(uint)_DAT_3ffbfc54[0x3f6] < *(int *)(iVar4 + 0xb4)) break;
      }
      memw();
      return 0;
    }
  }
  return uVar2;
}

