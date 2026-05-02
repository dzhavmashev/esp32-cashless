// Function : FUN_40134e20
// Address  : 0x40134e20
// Size     : 98 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40134e20(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_66 [66];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  puVar1 = (undefined4 *)FUN_40138f20();
  uVar2 = FUN_40138f28(*puVar1);
  iVar3 = -0x4d00;
  if ((param_3 < 0x43) && (iVar3 = FUN_40131900(param_2,auStack_66,param_3), iVar3 == 0)) {
    iVar3 = FUN_40138df0(param_1,uVar2,auStack_66,param_3);
  }
  FUN_4013ae54(auStack_66,param_3);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar3;
}

