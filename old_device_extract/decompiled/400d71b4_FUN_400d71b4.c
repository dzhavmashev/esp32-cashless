// Function : FUN_400d71b4
// Address  : 0x400d71b4
// Size     : 407 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d71b4(undefined4 param_1,int *param_2,undefined4 param_3,undefined2 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  piVar3 = param_2;
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    piVar3 = (int *)*param_2;
  }
  (*(code *)&SUB_40002c34)(param_3);
  FUN_400f06a4(0x3ffc5490,"02x%02x",piVar3);
  FUN_400f0be8(auStack_54,"tem=%u\n");
  FUN_400f0be8(auStack_34,"m=%u\n");
  uVar2 = FUN_400f10c0(auStack_34,param_2);
  uVar2 = FUN_400f10f0(uVar2,&DAT_3f40261e);
  FUN_400f0fa0(auStack_54,uVar2);
  FUN_400f0a50(auStack_34);
  FUN_400f0be8(auStack_34,"n_id\":\"");
  FUN_400f0e84(auStack_44,param_3,2);
  uVar2 = FUN_400f10c0(auStack_34,auStack_44);
  uVar2 = FUN_400f10f0(uVar2,"tials");
  FUN_400f0fa0(auStack_54,uVar2);
  FUN_400f0a50(auStack_44);
  FUN_400f0a50(auStack_34);
  FUN_400f1050(auStack_54,"mount\":");
  FUN_400f0be8(auStack_34,":\"KGS\",");
  FUN_400f0dd0(auStack_44,param_4,10);
  uVar2 = FUN_400f10c0(auStack_34,auStack_44);
  FUN_400f0fa0(auStack_54,uVar2);
  FUN_400f0a50(auStack_44);
  FUN_400f0a50(auStack_34);
  FUN_400f1050(auStack_54,"ialized\"}");
  FUN_400f0be8(auStack_34,"umber\":");
  FUN_400dba34(0x3ffc4218,auStack_34,auStack_54);
  FUN_400f0a50(auStack_34);
  FUN_400f0a50(auStack_54);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return;
  }
  func_0x40082ecc();
  do {
    FUN_400f0a50(auStack_34);
    FUN_400f0a50(auStack_54);
    thunk_FUN_401710d8(iVar1);
    FUN_400f0a50(auStack_44);
  } while( true );
}

