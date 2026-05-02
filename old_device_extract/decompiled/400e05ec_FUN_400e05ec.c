// Function : FUN_400e05ec
// Address  : 0x400e05ec
// Size     : 165 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e05ec(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  piVar2 = _DAT_3ffc405c;
  piVar3 = param_1 + 1;
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  if (_DAT_3ffc405c == (int *)0x0) {
    FUN_400f0be8(auStack_34,"machine");
    *param_1 = 1;
    FUN_400f0d4c(piVar3,auStack_34);
  }
  else {
    iVar1 = (**(code **)(*_DAT_3ffc405c + 0x1c))(_DAT_3ffc405c);
    if (iVar1 != 0) goto LAB_400e066a;
    FUN_400f0be8(auStack_34,"ailable");
    *param_1 = 1;
    FUN_400f0d4c(piVar3,auStack_34);
  }
  while( true ) {
    param_1[5] = 0;
    FUN_400f0a50(auStack_34);
    piVar3 = piStack_24;
    piVar2 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400e066a:
    (**(code **)(*piVar2 + 0x10))(piVar2);
    FUN_400f0be8(auStack_34," active");
    *param_1 = 0;
    FUN_400f0d4c(piVar3,auStack_34);
  }
  return;
}

