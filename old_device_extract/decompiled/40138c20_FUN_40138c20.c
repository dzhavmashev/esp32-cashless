// Function : FUN_40138c20
// Address  : 0x40138c20
// Size     : 238 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40138c20(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bStack_65;
  undefined1 auStack_64 [64];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  uVar1 = FUN_401864c4(*param_1);
  if ((param_2 == 0) || (puVar3 = (undefined4 *)0x2, param_3 == 0)) {
    puVar3 = (undefined4 *)0x1;
  }
  puVar4 = (undefined4 *)0x0;
  bStack_65 = 0;
  memw();
LAB_40138c4e:
  memw();
  puVar2 = (undefined4 *)FUN_401393f0(param_1);
  if (puVar2 != (undefined4 *)0x0) goto LAB_40138c89;
  puVar4 = param_1 + 3;
  puVar2 = (undefined4 *)FUN_4013935c(param_1,puVar4,uVar1);
  if (puVar2 != (undefined4 *)0x0) goto LAB_40138c89;
  puVar2 = (undefined4 *)FUN_4013935c(param_1,&bStack_65,1);
  if (puVar2 != (undefined4 *)0x0) goto LAB_40138c89;
  if (puVar3 == (undefined4 *)0x2) goto LAB_40138cb4;
  do {
    puVar2 = (undefined4 *)FUN_4013937c(param_1,auStack_64);
    if ((((puVar2 == (undefined4 *)0x0) &&
         (puVar2 = (undefined4 *)FUN_40139270(param_1,auStack_64,uVar1), puVar2 == (undefined4 *)0x0
         )) && (puVar2 = (undefined4 *)FUN_4013935c(param_1,puVar4,uVar1),
               puVar2 == (undefined4 *)0x0)) &&
       (puVar2 = (undefined4 *)FUN_4013937c(param_1,puVar4), puVar2 == (undefined4 *)0x0)) {
      bStack_65 = bStack_65 + 1;
      puVar4 = (undefined4 *)(uint)bStack_65;
      memw();
      if (puVar4 < puVar3) goto LAB_40138c4e;
      memw();
    }
LAB_40138c89:
    do {
      param_1 = puVar2;
      memw();
      FUN_4013ae54(auStack_64,0x40);
      param_3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      puVar3 = (undefined4 *)&DAT_3ffc5708;
LAB_40138cb4:
      puVar2 = (undefined4 *)FUN_4013935c(param_1,param_2,param_3);
    } while (puVar2 != (undefined4 *)0x0);
  } while( true );
}

