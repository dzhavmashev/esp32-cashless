// Function : FUN_4018a03c
// Address  : 0x4018a03c
// Size     : 493 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4018a03c(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  ushort uVar8;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x4ec);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  pcVar6 = *(char **)(*(int *)(param_2 + 4) + 4);
  if (*pcVar6 != -0x78) {
    return 0;
  }
  if ((pcVar6[1] & 3U) == 3) {
    bVar1 = pcVar6[0x1e];
  }
  else {
    bVar1 = pcVar6[0x18];
  }
  uVar5 = bVar1 & 0xf;
  if (uVar5 < 8) {
    puVar4 = *(uint **)(uVar5 * 4 + param_1 + 0x268);
    if (puVar4 == (uint *)0x0) {
      return 0;
    }
    uVar7 = *puVar4;
    if ((uVar7 & 4) == 0) {
      return 0;
    }
    uVar2 = *(ushort *)(pcVar6 + 0x16);
    uVar8 = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      uVar2 = uVar2 >> 4;
      uVar3 = (uint)uVar2;
      puVar4[5] = puVar4[5] + 1;
      if (((**(uint **)(param_2 + 0x2c) & 0x10) != 0) && ((uVar7 & 0x40) != 0)) {
        *puVar4 = uVar7 & 0xffffffbf;
        uVar8 = 1;
      }
      do {
        while( true ) {
          if (uVar3 == (ushort)puVar4[3]) {
            if ((short)puVar4[2] != 0) {
              memw();
              FUN_40189de4(param_1,param_2);
              FUN_40189e44(puVar4,param_1);
              return 1;
            }
            *(ushort *)(puVar4 + 3) = uVar2 + 1 & 0xfff;
            memw();
            memw();
            return 0;
          }
          uVar7 = (uVar3 + 0x1000) - (uint)(ushort)puVar4[3] & 0xfff;
          if (uVar7 < *(ushort *)((int)puVar4 + 0xe)) {
            if (*(int *)(puVar4[6] + uVar7 * 4) == 0) {
              if ((short)puVar4[2] == 0) {
                FUN_4014b2fc(300000);
              }
              uVar5 = puVar4[2];
              *(int *)(puVar4[6] + uVar7 * 4) = param_2;
              *(short *)(puVar4 + 2) = (short)uVar5 + 1;
              memw();
              puVar4[1] = puVar4[1] + (uint)*(ushort *)(param_2 + 0x16);
              memw();
              return 1;
            }
            goto LAB_4018a226;
          }
          if (0x7ff < uVar7) break;
          memw();
          FUN_40189f58(param_1,puVar4,
                       uVar3 + (0x1001 - (uint)*(ushort *)((int)puVar4 + 0xe)) & 0xfff);
LAB_4018a20e:
          memw();
        }
        if (uVar8 == 0) {
          if (((**(uint **)(param_2 + 0x2c) & 0x10) == 0) && ((*puVar4 & 0x40) != 0)) {
            memw();
            FUN_40189ecc(param_1,puVar4);
            *(ushort *)(puVar4 + 3) = uVar2;
            memw();
            goto LAB_4018a20e;
          }
          _DAT_3ffc7954 = _DAT_3ffc7954 + 1;
          memw();
          goto LAB_4018a226;
        }
        memw();
        FUN_40189ecc(param_1,puVar4);
        *(ushort *)(puVar4 + 3) = *(ushort *)((int)puVar4 + 10);
        memw();
        if (0x7ff < ((uVar3 + 0x1000) - (uint)*(ushort *)((int)puVar4 + 10) & 0xfff)) {
          *(ushort *)(puVar4 + 3) = uVar2 + (0x1001 - *(short *)((int)puVar4 + 0xe)) & 0xfff;
          memw();
        }
        memw();
        FUN_4015fdb0((char)puVar4[8],uVar5,(short)puVar4[3],0x40);
        uVar8 = 0;
      } while( true );
    }
    FUN_40147fe4(1,0x400,2,0x3f436618);
  }
  else {
    FUN_40147fe4(1,0x400,2,0x3f436637,uVar5);
  }
LAB_4018a226:
  memw();
  FUN_4015fb50(param_2);
  return 1;
}

