// Function : FUN_40152070
// Address  : 0x40152070
// Size     : 30 bytes


int FUN_40152070(int param_1,int param_2)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_2 + 0x2c);
  if (puVar1 != (undefined2 *)0x0) {
    (*(code *)&SUB_4008b3d0)(param_1,puVar1 + 1,*puVar1);
    param_1 = param_1 + (uint)**(ushort **)(param_2 + 0x2c);
  }
  return param_1;
}

