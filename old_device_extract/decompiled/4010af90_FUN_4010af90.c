// Function : FUN_4010af90
// Address  : 0x4010af90
// Size     : 52 bytes


void FUN_4010af90(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  uVar1 = (*(code *)&SUB_40094d60)(param_1);
  if (uVar1 == 0) {
    FUN_4011b020();
    FUN_4011b040();
  }
  else if (uVar1 != (uVar1 + 3 & 0xfffffffc)) {
    (*(code *)&SUB_40094c54)(" memory",0xf1,"em_free",&DAT_3f40fbbc);
    uVar2 = uVar1;
    if (uVar1 != 0) goto LAB_4010afdd;
    pcVar4 = "e/mem.c";
    uVar3 = 0x102;
    while( true ) {
      uVar2 = (*(code *)&SUB_40094c54)(" memory",uVar3,"N(rmem)",pcVar4);
LAB_4010afdd:
      if (uVar1 == (uVar1 + 3 & 0xfffffffc)) break;
      pcVar4 = "!= NULL";
      uVar3 = 0x103;
    }
    (*(code *)&SUB_40094d80)(uVar2);
    return;
  }
  return;
}

