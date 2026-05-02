// Function : FUN_401222ec
// Address  : 0x401222ec
// Size     : 61 bytes


undefined4 FUN_401222ec(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_24 [9];
  
  iVar1 = FUN_40122d44(param_1,auStack_24);
  if (iVar1 == 0) {
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc1447,uVar2,0x3ffc16cf,*param_1);
    uVar2 = 0xfffffffd;
  }
  else {
    uVar2 = FUN_40122194("e_check",1,auStack_24[0],iVar1);
  }
  return uVar2;
}

