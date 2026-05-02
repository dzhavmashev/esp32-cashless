// Function : FUN_401430dc
// Address  : 0x401430dc
// Size     : 377 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401430dc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,uint param_7,int param_8)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined4 uStack_a8;
  byte abStack_a4 [64];
  byte local_64 [64];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  memw();
  uVar1 = FUN_401864c4(*param_1);
  uStack_a8 = 0x1000000;
  memw();
  memw();
  puVar2 = (undefined4 *)FUN_40139270(param_1,param_2,param_3);
  if (puVar2 != (undefined4 *)0x0) goto LAB_4014314e;
  do {
    puVar3 = puVar2;
    if (param_7 != 0) goto LAB_4014316a;
LAB_4014312e:
    do {
      memw();
      FUN_4013ae54(local_64,0x40);
      FUN_4013ae54(abStack_a4,0x40);
      puVar2 = puVar3;
LAB_4014314e:
      param_1 = puVar2;
      puVar2 = _DAT_3ffc5708;
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_4014316a:
      puVar3 = (undefined4 *)FUN_4013935c(param_1,param_4,param_5);
    } while ((((puVar3 != (undefined4 *)0x0) ||
              (puVar3 = (undefined4 *)FUN_4013935c(param_1,&uStack_a8,4),
              puVar3 != (undefined4 *)0x0)) ||
             (puVar3 = (undefined4 *)FUN_4013937c(param_1,local_64), puVar3 != (undefined4 *)0x0))
            || (puVar3 = (undefined4 *)FUN_401393f0(param_1), puVar3 != (undefined4 *)0x0));
    (*(code *)&SUB_4008b3d0)(abStack_a4,local_64,uVar1);
    for (uVar5 = 1; uVar5 < param_6; uVar5 = uVar5 + 1) {
      puVar3 = (undefined4 *)FUN_4013935c(param_1,abStack_a4,uVar1);
      if (((puVar3 != (undefined4 *)0x0) ||
          (puVar3 = (undefined4 *)FUN_4013937c(param_1,abStack_a4), puVar3 != (undefined4 *)0x0)) ||
         (puVar3 = (undefined4 *)FUN_401393f0(param_1), puVar3 != (undefined4 *)0x0))
      goto LAB_4014312e;
      pbVar7 = local_64;
      iVar6 = 0;
      while (iVar6 < (int)uVar1) {
        pbVar8 = abStack_a4 + iVar6;
        iVar6 = iVar6 + 1;
        *pbVar7 = *pbVar8 ^ *pbVar7;
        memw();
        pbVar7 = pbVar7 + 1;
        memw();
      }
    }
    iVar6 = (uVar1 < param_7) * uVar1 + (uVar1 >= param_7) * param_7;
    (*(code *)&SUB_4008b3d0)(param_8,local_64,iVar6);
    param_8 = param_8 + iVar6;
    param_7 = param_7 - iVar6;
    iVar6 = 4;
    puVar3 = &uStack_a8;
    do {
      iVar6 = iVar6 + -1;
      cVar4 = *(char *)((int)puVar3 + 3) + '\x01';
      *(char *)((int)puVar3 + 3) = cVar4;
      memw();
      puVar3 = (undefined4 *)((int)puVar3 + -1);
    } while (cVar4 == '\0' && iVar6 != 0);
    memw();
  } while( true );
}

