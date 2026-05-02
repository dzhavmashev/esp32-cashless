// Function : FUN_4010ffc8
// Address  : 0x4010ffc8
// Size     : 291 bytes


undefined4 * FUN_4010ffc8(int param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint in_t0;
  
  uVar8 = param_2;
  if (param_1 != 0) goto LAB_4010ffe4;
  pcVar10 = "p_input";
  uVar9 = 0xa3;
  uVar6 = param_5;
  uVar8 = in_t0;
  while( true ) {
    while( true ) {
      (*(code *)&SUB_40094c54)("lid pcb",uVar9,"ent_seg",pcVar10);
      param_5 = uVar6;
      in_t0 = uVar8;
LAB_4010ffe4:
      if (param_2 != 0) break;
      pcVar10 = "p_out.c";
      uVar9 = 0xa4;
      uVar6 = param_5;
      uVar8 = in_t0;
    }
    param_2 = (param_5 & 1) << 2;
    memw();
    puVar3 = (undefined4 *)FUN_4010b058();
    if (puVar3 == (undefined4 *)0x0) break;
    *(char *)((int)puVar3 + 10) = (char)param_5;
    memw();
    uVar6 = 0;
    uVar1 = *(ushort *)(uVar8 + 8);
    *puVar3 = 0;
    puVar3[1] = uVar8;
    if (param_2 <= uVar1) {
      *(ushort *)(puVar3 + 2) = uVar1 - (short)param_2;
      memw();
      memw();
      iVar4 = FUN_4010ba7c(uVar8,0x14);
      if (iVar4 == 0) {
        puVar7 = *(undefined1 **)(puVar3[1] + 4);
        uVar2 = *(undefined2 *)(param_1 + 0x42);
        puVar3[3] = puVar7;
        memw();
        uVar2 = FUN_40185288(uVar2);
        *puVar7 = (char)uVar2;
        puVar7[1] = (char)((ushort)uVar2 >> 8);
        memw();
        iVar4 = puVar3[3];
        memw();
        uVar2 = FUN_40185288(*(undefined2 *)(param_1 + 0x44));
        *(char *)(iVar4 + 2) = (char)uVar2;
        *(char *)(iVar4 + 3) = (char)((ushort)uVar2 >> 8);
        memw();
        iVar4 = puVar3[3];
        memw();
        uVar9 = FUN_40109eec(param_4);
        *(char *)(iVar4 + 4) = (char)uVar9;
        *(char *)(iVar4 + 5) = (char)((uint)uVar9 >> 8);
        *(char *)(iVar4 + 7) = (char)((uint)uVar9 >> 0x18);
        *(char *)(iVar4 + 6) = (char)((uint)uVar9 >> 0x10);
        memw();
        iVar5 = puVar3[3];
        memw();
        uVar2 = FUN_40185288(((param_5 & 1) + 5) * 0x1000 | param_3);
        *(char *)(iVar5 + 0xc) = (char)uVar2;
        memw();
        iVar4 = puVar3[3];
        *(char *)(iVar5 + 0xd) = (char)((ushort)uVar2 >> 8);
        *(undefined1 *)(iVar4 + 0x12) = 0;
        *(undefined1 *)(iVar4 + 0x13) = 0;
        memw();
        memw();
      }
      else {
        FUN_4010ce44(puVar3);
        puVar3 = (undefined4 *)0x0;
      }
      return puVar3;
    }
    pcVar10 = "id pbuf";
    uVar9 = 0xb0;
    memw();
    uVar8 = in_t0;
  }
  FUN_4010bb10(uVar8);
  return (undefined4 *)0x0;
}

