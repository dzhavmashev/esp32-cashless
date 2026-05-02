// Function : FUN_40105afc
// Address  : 0x40105afc
// Size     : 262 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40105afc(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,uint param_8,int param_9,undefined4 param_10)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 uStack_54;
  undefined1 auStack_53 [13];
  undefined1 uStack_46;
  undefined1 uStack_45;
  byte local_44 [16];
  byte local_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uVar2 = 0x1e;
  if ((param_8 < 0x1f) && (uVar2 = 0x10, param_4 < 0x11)) {
    memw();
    iVar1 = FUN_40102184(param_1,param_2);
    uVar2 = 0;
    if (iVar1 != 0) goto LAB_40105b5a;
  }
  iVar1 = -1;
  while( true ) {
    param_3 = iStack_24;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
LAB_40105b5a:
    uStack_54 = 1;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_53,param_3,0xd);
    uStack_46 = (undefined1)uVar2;
    memw();
    memw();
    uStack_45 = uStack_46;
    FUN_401021b8(iVar1,&uStack_54,local_34);
    while (param_4 != uVar2) {
      pbVar4 = local_44 + uVar2;
      pbVar3 = (byte *)(param_9 + uVar2);
      pbVar5 = local_34 + uVar2;
      uVar2 = uVar2 + 1;
      *pbVar4 = *pbVar3 ^ *pbVar5;
      memw();
      memw();
    }
    FUN_40105890(iVar1,param_5,param_6,param_10,&uStack_54);
    memw();
    FUN_40105924(iVar1,param_4,param_3,param_7,param_8,param_6,local_34);
    FUN_40105834(iVar1,param_10,param_6,local_34);
    FUN_401021d0(iVar1);
    iVar1 = (*(code *)&SUB_4008b33c)(local_34,local_44,param_4);
    iVar1 = -(uint)(iVar1 != 0);
  }
  return;
}

