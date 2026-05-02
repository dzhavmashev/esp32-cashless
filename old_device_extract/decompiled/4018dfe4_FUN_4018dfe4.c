// Function : FUN_4018dfe4
// Address  : 0x4018dfe4
// Size     : 300 bytes


uint * FUN_4018dfe4(uint param_1,uint *param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *extraout_a3;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  char *pcVar10;
  uint in_t0;
  
  uVar3 = param_3 - 8U & 0xfffffffc;
  if (((uint)param_2 & 3) == 0) {
    uVar1 = (*(code *)&SUB_40093dec)(param_1);
    if ((0xb < uVar3) && (uVar3 <= uVar1)) {
      puVar8 = param_2 + -1;
      *param_2 = *param_2 & 1 | uVar3 | 1;
      uVar5 = *(uint *)(param_1 + 0x10);
      uVar4 = uVar5 >> 0x17 & 0xff;
      uVar1 = 0;
      if (uVar4 <= uVar3) goto LAB_4018e076;
      uVar3 = (int)uVar3 / (int)(uVar4 / (uVar5 >> 0xe & 0x3f));
      uVar4 = 0;
      do {
        iVar9 = *(int *)(param_1 + 0x20);
        uVar5 = *(uint *)(iVar9 + ((uVar5 >> 0xe & 0x3f) * uVar4 + uVar3) * 4);
        if (uVar5 == 0) {
          uVar7 = 0xe9;
          pcVar10 = "bytes.\n";
        }
        else {
          puVar8[2] = uVar5;
          puVar8[3] = param_1;
          *(uint **)(uVar5 + 0xc) = puVar8;
          if (puVar8 + 2 == (uint *)((int)puVar8 + 0xbU & 0xfffffffc)) {
            uVar1 = *(uint *)(param_1 + 0x18);
            *(uint **)(iVar9 + ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar4 + uVar3) * 4) =
                 puVar8;
            *(uint *)(param_1 + 0x18) = uVar1 | 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
            puVar6 = (uint *)(*(int *)(param_1 + 0x1c) + uVar4 * 4);
            *puVar6 = *puVar6 | 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
            puVar2 = (undefined4 *)((puVar8[1] & 0xfffffffc) + (int)(puVar8 + 2));
            puVar2[-1] = puVar8;
            *puVar2 = 2;
            memw();
            return param_2;
          }
          uVar7 = 0xef;
          pcVar10 = "_tlsf.c";
          memw();
        }
        memw();
        uVar5 = in_t0;
        (*(code *)&SUB_40094c54)("ts/heap/heap_tlsf.c",uVar7,"e_block",pcVar10);
        uVar3 = uVar5;
        puVar8 = extraout_a3;
        in_t0 = uVar5;
LAB_4018e076:
        uVar4 = uVar1;
        if (uVar3 != 0) {
          uVar4 = 0x20 - LZCOUNT(uVar3);
        }
        uVar1 = (uVar4 - 1) - (uVar5 >> 0x14 & 7);
        uVar3 = uVar3 >> (uVar1 & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar5 >> 0x14 & 7));
        uVar4 = uVar4 - (uVar5 >> 5 & 7);
      } while( true );
    }
    FUN_4017403c("bytes.\n",0x14,uVar1 + 8);
  }
  else {
    FUN_4017403c("x (%p)\n",4);
  }
  return (uint *)0x0;
}

