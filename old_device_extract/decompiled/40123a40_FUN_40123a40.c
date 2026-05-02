// Function : FUN_40123a40
// Address  : 0x40123a40
// Size     : 56 bytes


undefined4 FUN_40123a40(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_26 [38];
  
  puVar1 = (undefined4 *)FUN_40159fac();
  FUN_4015a5a0(0,auStack_26);
  uVar2 = FUN_4015a158();
  uVar3 = FUN_4015a168();
  uVar4 = FUN_4015a08c();
  memw();
  uVar2 = FUN_401046fc(auStack_26,param_1,uVar2,uVar3,uVar4,puVar1 + 1,*puVar1);
  return uVar2;
}

