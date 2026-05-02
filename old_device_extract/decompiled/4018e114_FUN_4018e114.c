// Function : FUN_4018e114
// Address  : 0x4018e114
// Size     : 343 bytes


uint FUN_4018e114(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  uint in_t0;
  
  if (param_1 != 0) {
    if ((param_1 & 3) == 0) {
      if (0x23 < param_2) {
        uVar3 = 0x20U - LZCOUNT(param_2) & 0xff;
        uVar5 = (0x20U - LZCOUNT(param_2) & 0x3f) << 8;
        uVar1 = *(uint *)(param_1 + 0x10);
        uVar2 = uVar1 & 0xffffc0ff | uVar5;
        *(uint *)(param_1 + 0x10) = uVar2;
        uVar6 = 0xff8fffff;
        if (param_2 < 0x4001) {
          uVar6 = uVar1 & 0xff8fc0ff | uVar5;
          uVar1 = 0x300000;
          uVar2 = in_t0;
          goto LAB_4018e165;
        }
        while( true ) {
          uVar6 = uVar2 & uVar6;
          uVar1 = 0x400000;
          uVar2 = in_t0;
          if (0x40000 < param_2) {
            uVar1 = 0x500000;
          }
LAB_4018e165:
          *(uint *)(param_1 + 0x10) = uVar6 | uVar1;
          uVar6 = *(uint *)(param_1 + 0x10) >> 0x14;
          uVar1 = (uVar6 & 7) + 2;
          uVar6 = 1 << 0x20 - (0x20 - (uVar6 & 7));
          uVar5 = uVar6 & 0x3f;
          uVar6 = uVar6 & 0x3f;
          uVar3 = uVar3 + (1 - (uVar1 & 7)) & 0x1f;
          uVar10 = 1 << 0x20 - (0x20 - (uVar1 & 7));
          *(uint *)(param_1 + 0x10) =
               *(uint *)(param_1 + 0x10) & 0x80703f00 | (uVar1 & 7) << 5 | uVar6 << 0xe | uVar3 |
               (uVar10 & 0xff) << 0x17;
          iVar4 = (uVar3 + 9 + uVar3 * uVar5) * 4;
          *(int *)(param_1 + 0x14) = iVar4;
          if (param_2 < iVar4 + 0xcU) break;
          uVar1 = param_1 + 0x27 & 0xfffffffc;
          iVar4 = uVar1 + uVar3 * 4;
          iVar7 = 0;
          *(uint *)(param_1 + 8) = param_1;
          *(uint *)(param_1 + 0xc) = param_1;
          *(undefined4 *)(param_1 + 0x18) = 0;
          *(uint *)(param_1 + 0x1c) = uVar1;
          *(int *)(param_1 + 0x20) = iVar4;
          if (uVar6 < 0x21) {
            if ((int)uVar10 / (int)uVar5 == 4) {
              for (; iVar7 < (int)(*(uint *)(param_1 + 0x10) & 0x1f); iVar7 = iVar7 + 1) {
                *(undefined4 *)(iVar7 * 4 + uVar1) = 0;
                iVar9 = 0;
                while (uVar3 = *(uint *)(param_1 + 0x10) >> 0xe & 0x3f, iVar9 < (int)uVar3) {
                  *(uint *)(iVar4 + (iVar7 * uVar3 + iVar9) * 4) = param_1;
                  iVar9 = iVar9 + 1;
                  memw();
                }
              }
              memw();
              return param_1;
            }
            pcVar11 = "_count\"";
            uVar8 = 0x1fe;
          }
          else {
            uVar8 = 0x1fb;
            pcVar11 = "bytes.\n";
          }
          memw();
          uVar6 = (*(code *)&SUB_40094c54)("ts/heap/heap_tlsf.c",uVar8,"te_free",pcVar11);
          param_2 = 0x20;
          uVar3 = uVar2;
          in_t0 = uVar2;
        }
      }
    }
    else {
      FUN_4017403c("e null\"",4);
    }
  }
  return 0;
}

