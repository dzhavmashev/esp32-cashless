// Function : FUN_400dbcd0
// Address  : 0x400dbcd0
// Size     : 493 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dbcd0(uint param_1,int *param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 auStack_4c [8];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  puVar6 = (undefined1 *)0x3ffc5490;
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) goto LAB_400dbd18;
  uVar7 = (uint)param_2[3] >> 0x18 & 0x7f;
  do {
    if (uVar7 != 0) {
      FUN_400f0d18(param_1,param_2);
      FUN_400f0d18(param_1 + 0x10,param_3);
      FUN_400f0be8(auStack_34,"rovided");
      uVar2 = FUN_400f10c0(auStack_34,param_2);
      FUN_400f0768(puVar6,uVar2);
      FUN_400f0a50(auStack_34);
      if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
        param_2 = (int *)*param_2;
      }
      if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
        param_3 = (int *)*param_3;
      }
      FUN_400e90f4(&DAT_3ffc516c,param_2,param_3,0,0,1);
      iVar3 = FUN_400f1a9c();
      iVar5 = 0;
      while ((iVar4 = FUN_400e90d8(), iVar5 < 10 && (iVar4 != 3))) {
        iVar4 = FUN_400f1a9c();
        if (999 < (uint)(iVar4 - iVar3)) {
          FUN_400f0740(puVar6,"Title");
          iVar3 = FUN_400f1a9c();
          iVar5 = iVar5 + 1;
        }
        FUN_400e7850(0x3ffc5158);
        FUN_400f1ab4(10);
      }
      iVar3 = FUN_400e90d8();
      *(bool *)(param_1 + 0x20) = iVar3 == 3;
      if (iVar3 == 3) {
        FUN_400f0780(puVar6,"ing to ");
        FUN_400f0be8(auStack_34,"sfully!");
        FUN_400e9690(auStack_4c,&DAT_3ffc516c);
        FUN_400f0598(auStack_44,auStack_4c);
        uVar2 = FUN_400f10c0(auStack_34,auStack_44);
        FUN_400f0768(puVar6,uVar2);
        FUN_400f0a50(auStack_44);
        FUN_400f0a50(auStack_34);
        FUN_400f0be8(auStack_34,"sfully!");
        cVar1 = FUN_400e979c(&DAT_3ffc516c);
        FUN_400f0dd0(auStack_44,(int)cVar1,10);
        uVar2 = FUN_400f10c0(auStack_34,auStack_44);
        uVar2 = FUN_400f10f0(uVar2,"");
        FUN_400f0768(puVar6,uVar2);
        FUN_400f0a50(auStack_44);
        FUN_400f0a50(auStack_34);
      }
      else {
        FUN_400f0780(puVar6,&DAT_3f405238);
        FUN_400e9570(&DAT_3ffc516c,0,0);
      }
      param_1 = (uint)*(byte *)(param_1 + 0x20);
      goto LAB_400dbcff;
    }
    do {
      FUN_400f0780(puVar6,&DAT_3f4051cc);
      param_1 = 0;
LAB_400dbcff:
      param_3 = piStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (piStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
      puVar6 = &DAT_3ffc5708;
LAB_400dbd18:
    } while (*param_2 == 0);
    uVar7 = param_2[2];
  } while( true );
}

