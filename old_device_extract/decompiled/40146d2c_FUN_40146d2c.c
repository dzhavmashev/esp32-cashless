// Function : FUN_40146d2c
// Address  : 0x40146d2c
// Size     : 74 bytes


undefined4 FUN_40146d2c(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_401460c8();
  uVar3 = 0x3001;
  if (((iVar2 != 0) && (uVar3 = 0x3002, 1 < DAT_3ffc89d9)) &&
     (uVar3 = 0x102, param_1 != (undefined2 *)0x0)) {
    FUN_4014605c();
    uVar1 = FUN_40155424();
    *param_1 = uVar1;
    memw();
    memw();
    FUN_401460a4();
    FUN_40147fe4(1,0xb,5,0x3f435c1e,*param_1);
    uVar3 = 0;
  }
  return uVar3;
}

