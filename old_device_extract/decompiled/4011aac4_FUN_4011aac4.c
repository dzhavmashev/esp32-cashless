// Function : FUN_4011aac4
// Address  : 0x4011aac4
// Size     : 111 bytes


undefined1
FUN_4011aac4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  
  uVar2 = FUN_40185290(param_5);
  iVar3 = FUN_4010ba7c(param_2,0xe);
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_2 + 4);
    *(char *)(iVar3 + 0xc) = (char)uVar2;
    *(char *)(iVar3 + 0xd) = (char)((ushort)uVar2 >> 8);
    memw();
    memw();
    iVar3 = (*(code *)&SUB_4008b3d0)(iVar3,param_4,6);
    (*(code *)&SUB_4008b3d0)(iVar3 + 6,param_3);
    if (*(char *)(param_1 + 0xea) != '\x06') {
      (*(code *)&SUB_40094c54)("output!",0x133,"ernet.c","_prefix");
    }
    uVar1 = (**(code **)(param_1 + 0xbc))(param_1,param_2);
  }
  else {
    uVar1 = 0xfe;
  }
  return uVar1;
}

