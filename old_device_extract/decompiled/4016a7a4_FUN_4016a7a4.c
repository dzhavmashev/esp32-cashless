// Function : FUN_4016a7a4
// Address  : 0x4016a7a4
// Size     : 191 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016a7a4(void)

{
  char cVar1;
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  
  uStack_2c = _DAT_3ffc32fc;
  uStack_2a = _DAT_3ffc32fe;
  local_30 = _DAT_3ffc32f8;
  uStack_2e = _DAT_3ffc32fa;
  memw();
  (**(code **)(_DAT_3ffc7e64 + 0xc0))();
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(4,1,0);
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(5,1,0);
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(0,1,0x184);
  cVar1 = '\x01';
  do {
    if (cVar1 == '\x01') {
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,1,0x189);
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,0);
      (**(code **)(_DAT_3ffc7e64 + 0xdc))(&local_30);
    }
    else {
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,1,0x18b);
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,0);
      (**(code **)(_DAT_3ffc7e64 + 0xdc))(&local_30);
      if (cVar1 == '\x02') {
        (**(code **)(_DAT_3ffc7e64 + 0xc4))();
        return;
      }
    }
    cVar1 = cVar1 + '\x01';
  } while( true );
}

