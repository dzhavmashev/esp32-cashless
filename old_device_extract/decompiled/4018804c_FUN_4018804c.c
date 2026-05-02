// Function : FUN_4018804c
// Address  : 0x4018804c
// Size     : 602 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018804c(int *param_1,char param_2,char param_3)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  char cVar8;
  undefined1 auStack_30 [2];
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  if (param_3 == '\0') {
    if (*(char *)((int)param_1 + 0x12) == '\x06') {
      *(undefined1 *)((int)param_1 + 0x12) = 0;
      memw();
      iVar6 = *param_1;
      if (param_2 == '\0') {
        uVar2 = 9;
        if (iVar6 == 0) {
          memw();
          FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"llision",0x40b);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
      }
      else {
        uVar2 = 10;
      }
      *(undefined1 *)((int)param_1 + 0x13) = uVar2;
      memw();
      puVar4 = *(uint **)(iVar6 + 0x2c);
      if ((*puVar4 & 0x200000) != 0) {
        memw();
        FUN_40163050(puVar4[4] >> 0x14 & 0xf,*(char *)((int)puVar4 + 5) + '\x02');
        FUN_40188f54(*(uint *)(*(int *)(iVar6 + 0x2c) + 0x10) >> 0x14 & 0xf);
        return;
      }
      if ((*puVar4 & 0x400000) != 0) {
        FUN_40163c48(iVar6,1);
        return;
      }
      uVar7 = 2;
      if ((*(byte *)((int)puVar4 + 6) < DAT_3ffbfff5) &&
         (uVar7 = 4, DAT_3ffbfff4 <= *(byte *)((int)puVar4 + 7))) {
        uVar7 = 3;
      }
      FUN_401603f4(param_1,iVar6,uVar7,1);
      return;
    }
    if (*(char *)((int)param_1 + 0x12) != '\x05') {
      memw();
      FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"llision",0x44c);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar6 = *param_1;
    *(undefined1 *)((int)param_1 + 0x12) = 0;
    memw();
    if (iVar6 == 0) {
      memw();
      FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"llision",0x42b);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if ((**(uint **)(iVar6 + 0x2c) & 0x80000) == 0) {
      if ((**(uint **)(iVar6 + 0x2c) & 0x400000) == 0) {
        *(undefined1 *)((int)param_1 + 0x13) = 3;
        memw();
        memw();
        FUN_40188010(param_1,iVar6,1);
        return;
      }
      *(undefined1 *)((int)param_1 + 0x13) = 2;
      memw();
      memw();
      iVar6 = FUN_40189c90(*(undefined4 *)(iVar6 + 0x24));
      if (iVar6 != 0) {
        FUN_40162f2c(*(uint *)(*(int *)(*param_1 + 0x2c) + 4) & 0xf,
                     *(uint *)(*(int *)(*param_1 + 0x2c) + 0x10) >> 0x14 & 0xf);
        return;
      }
      FUN_40163cb0(*param_1,1);
      return;
    }
    (*(code *)&SUB_4008b530)(auStack_30,0,0xc);
    FUN_40189bac((char)param_1[1],auStack_30);
    puVar4 = *(uint **)(*param_1 + 0x2c);
    uVar5 = puVar4[4];
    if ((*puVar4 & 0x200000) == 0) {
      iVar6 = _DAT_3ffc0034 + (uVar5 >> 0x14 & 0xf) * 0x30;
      uVar2 = FUN_40189c38((char)param_1[1]);
      *(undefined1 *)(iVar6 + 0x4d) = uVar2;
      memw();
      uVar5 = *(uint *)(*(int *)(*param_1 + 0x2c) + 0x10);
      memw();
      cVar8 = '\0';
    }
    else {
      cVar8 = *(char *)((int)puVar4 + 5) + '\x01';
    }
    FUN_40163070(uVar5 >> 0x14 & 0xf,uStack_2e,uStack_2c,uStack_28,cVar8);
    FUN_40188f54(*(uint *)(*(int *)(*param_1 + 0x2c) + 0x10) >> 0x14 & 0xf);
    uVar2 = 1;
  }
  else {
    if (1 < (byte)(*(char *)((int)param_1 + 0x12) - 1U)) {
      memw();
      FUN_40147fe4(6,0x800,1," %s %u\n",&PTR_DAT_3f4243a8,"llision",0x44f);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (param_2 == '\0') {
      *(undefined1 *)((int)param_1 + 0x12) = 3;
      memw();
      memw();
      FUN_401604d4(param_1);
      uVar2 = 5;
    }
    else {
      iVar6 = *param_1;
      if ((((**(uint **)(iVar6 + 0x2c) & 0x400000) != 0) &&
          (bVar1 = *(byte *)((int)*(uint **)(iVar6 + 0x2c) + 5), DAT_3ffc000b <= bVar1)) &&
         ((iVar3 = FUN_401600f4(iVar6), iVar3 != 0 || (DAT_3ffc000c <= bVar1)))) {
        FUN_40160384(param_1,iVar6);
        return;
      }
      *(undefined1 *)((int)param_1 + 0x12) = 3;
      memw();
      memw();
      FUN_401604d4(param_1,0);
      uVar2 = 7;
    }
  }
  *(undefined1 *)((int)param_1 + 0x13) = uVar2;
  memw();
  memw();
  return;
}

