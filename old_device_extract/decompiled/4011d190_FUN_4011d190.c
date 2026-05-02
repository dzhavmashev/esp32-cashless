// Function : FUN_4011d190
// Address  : 0x4011d190
// Size     : 77 bytes


void FUN_4011d190(int param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (*(int *)(param_1 + 8) == 0) goto LAB_4011d1a9;
  pcVar2 = "nn_type";
  uVar1 = 0x340;
  while( true ) {
    while( true ) {
      (*(code *)&SUB_40094c54)("rgument",uVar1,"n_drain",pcVar2);
LAB_4011d1a9:
      FUN_4011d1e0(param_1);
      if (*(int *)(param_1 + 0x10) == 0) break;
      pcVar2 = "unction";
      uVar1 = 0x348;
    }
    if (*(int *)(param_1 + 0x14) == 0) break;
    pcVar2 = "unction";
    uVar1 = 0x34b;
  }
  FUN_4010b078(7,param_1);
  return;
}

